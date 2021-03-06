/*************************************************************************
	> File Name: http.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月24日 星期六 14时27分55秒
 ************************************************************************/

#include <iostream>
using namespace std;

#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdarg.h>
#include <memory>
#include <errno.h>
#include "buffer.h"

class http {
public:
    http(char *, size_t);

    //文件名的最大长度
    static const int FILENAME_LEN = 200;
    
    //http请求方法, 但目前支持只get
    enum METHOD { GET = 0, POST, HEAD, PUT, DELETE, 
                 TRACE, OPTIONS, CONNECT, PATCH };
    //
    enum CHECK_STATE { CHECK_STATE_REQUESTLINE = 0,
                       CHECK_STATE_HEADER,
                       CHECK_STATE_CONTENT };

    //服务器处理http请求可能的结果
    //NO_REQUEST请求不完整需要继续读取, GET_REQUEST获得完整的客户请求
    //BAD_REQUEST客户请求有语法错误     NO_RESQURCE没有该资源
    //FORBIDDEN_REQUEST权限不够         FILE_REQUEST
    //INTERNAL_ERROR 服务器内部错误     CLOSED_CONNECTION 客户端已经关闭连接
    enum HTTP_CODE { NO_REQUEST, GET_REQUEST, BAD_REQUEST,
                     NO_RESQURCE, FORBIDDEN_REQUEST, FILE_REQUEST,
                     INTERNAL_ERROR, CLOSED_CONNECTION };
    //行的读取状态
    enum LINE_STATUS { LINE_OK = 0, LINE_BAD, LINE_OPEN };

    ~http();


private:
    //解析http请求
    HTTP_CODE process_read();
    //填充http请求
    bool process_write(HTTP_CODE ret);

    //process_read调用解析http请求
    HTTP_CODE parse_request_line(char *);
    HTTP_CODE parse_headers(char *);
    HTTP_CODE parse_content(char *);
    HTTP_CODE do_request();
    LINE_STATUS parse_line();

    //process_write调用填充http应答
    void unmap();
    bool add_response(const char *format, ...);
    bool add_content(const char *content);
    bool add_status_line(int status, const char *title);
    bool add_headers(int content_length);
    bool add_content_length(int content_length);
    bool add_linger();
    bool add_blank_line();


private:
    CHECK_STATE m_check_state;   //主状态机当前所处状态
    METHOD m_method;             //请求方法

    char m_real_file[FILENAME_LEN];   //客户请求的目标文件的完整路径
    char *m_url;                      //客户请求的目标文件的文件名
    char *m_version;                  //http协议的版本号, 我们只支持HTTP/1.1
    char *m_host;                     //主机名
    int m_content_length;             //http请求的消息体长度
    bool m_linger;                    //http请求是否要求保持连接

    char *m_file_address;             //客户请求的目标文件被mmap到内存的起始位置
    struct stat m_file_stat;          //目标文件的状态
    
    char doc_root[10] = "/";
    char *input;
    //check用于控制字符的移动,但要检查改行字符是否LINE_OK
    char *m_checked_index_;
    //start_line用于记录行的起始位置,如果满足LINE_OK, 移动它 
    char *m_start_line_;
    size_t read_size;
};


const char *ok_200_title = "OK";
const char *error_400_title = "Bad Request";
const char *error_400_form = "Your request has bad syntax ot is inherently impossible to satisfy.\n";
const char *error_403_title = "Bad Forbidden";
const char *error_403_form = "Your do not have permission to get file from this server.\n";
const char *error_404_title = "Not found";
const char *error_404_form = "The request file was not found on this server.\n";
const char *error_500_title = "Bad Request";
const char *error_500_form = "There wan an unusual problem serving this requested file.\n";

http::http(char *input, size_t size)
  : input(input),
    m_checked_index_(input),
    m_start_line_(input),
    read_size(size)
{
    m_check_state = CHECK_STATE_REQUESTLINE;
    m_checked_index_ = input;
    m_start_line_ = input;
    m_linger = false;

    m_method = GET;
    m_url = 0;
    m_version = 0;
    m_content_length = 0;
    m_host = 0;
}

http::HTTP_CODE http::process_read()
{
    LINE_STATUS line_status= LINE_OK;
    HTTP_CODE ret =  NO_REQUEST;
    char *text;

    while(((m_check_state == CHECK_STATE_CONTENT) && (line_status == LINE_OK)) ||
        ((line_status = parse_line())== LINE_OK)) {
        text = m_start_line_;
        m_start_line_ = m_checked_index_;
        switch (m_check_state) {
            case CHECK_STATE_REQUESTLINE: {
                ret = parse_request_line(text);
                if(ret = BAD_REQUEST) {
                    return BAD_REQUEST;
                }
                break;
            }
            case CHECK_STATE_HEADER: {
                ret = parse_headers(text);
                if (ret == BAD_REQUEST) {
                    return BAD_REQUEST;
                }
                else if (ret == GET_REQUEST) {
                    return do_request();
                }
                break;
            }
            case CHECK_STATE_CONTENT: {
                ret = parse_content(text);
                if (ret = GET_REQUEST) {
                    return do_request();
                }
                line_status = LINE_OPEN;
                break;
            }
            default: 
                return INTERNAL_ERROR;
        }
    }
    return NO_REQUEST;
}

http::LINE_STATUS http::parse_line()
{
    char temp;
    for (; m_checked_index_ < input + read_size; m_checked_index_++) {
        temp = *m_checked_index_;
        if (temp == '\r') {
            if ((m_checked_index_ + 1) == input + read_size) {
                return LINE_OPEN;
            }
            else if (*(m_checked_index_ + 1)= '\n') {
                return LINE_OK;
            }
            return LINE_BAD;
        }
        else if (temp == '\n') {
            if (m_checked_index_ - input > 1 && 
                    *(m_checked_index_ - 1) == '\r')  {
                return LINE_OK;
            }
            return LINE_BAD;
        }
    }
    return LINE_OPEN;
}

http::HTTP_CODE http::parse_request_line(char *text)
{
    
    m_url = strpbrk(text, "\t");
    if (!m_url) {
        return BAD_REQUEST;
    }
    *m_url++ = '\0';

    char *method = text;
    if (strcasecmp(method, "GET") == 0) {
        m_method = GET;
    }
    else {
        return BAD_REQUEST;
    }
    m_url += strspn(m_url, "\t");
    m_version = strpbrk(m_url, "\t");
    if (!m_version) {
        return BAD_REQUEST;
    }
    *m_version++ = '\0';
    m_version +=strspn(m_version, "\t");
    if (strcasecmp(m_version, "HTTP/1.1") != 0) {
        return BAD_REQUEST;
    }
    if (strncasecmp(m_url, "http://", 7) == 0) {
        m_url += 7;
        m_url = strchr(m_url, '/');
    }
    if (!m_url || m_url[0] != '/') {
        return BAD_REQUEST;
    }
    m_check_state = CHECK_STATE_HEADER;
    return NO_REQUEST;
}


http::HTTP_CODE http::parse_headers(char *text)
{
    if (text[0] == '\0') {
        if (m_content_length != 0) {
            m_check_state = CHECK_STATE_CONTENT;
            return NO_REQUEST;
        }
        return GET_REQUEST;
    }
    else if (strncasecmp(text, "Connection:", 11) == 0) {
        text += 11;
        text += strspn(text, "\t");
        if (strcasecmp(text, "keep-alive") == 0) {
            m_linger = true;
        }
    }
    else if (strncasecmp(text, "Content-Length:", 15) == 0) {
        text += 15;
        text += strspn(text, "\t");
        m_content_length = atol(text);
    }
    else if (strncasecmp(text, "Host:", 5) == 0) {
        text += 5;
        text += strspn(text, "\t");
        m_host = text;
    }
    else {
        cout << "oop! unkonw header " <<text << endl;
    }
    return NO_RESQURCE;
}

http::HTTP_CODE http::parse_content(char *text)
{
    return GET_REQUEST;    
}

http::HTTP_CODE http::do_request()
{
    strcpy(m_real_file, doc_root);
    int len = strlen(doc_root);
    strncpy(m_real_file + len, m_url, FILENAME_LEN - len -1);
    if (stat(m_real_file, &m_file_stat) < 0) {
        return NO_RESQURCE;
    }
    if (!m_file_stat.st_mode & S_IROTH) {
        return FORBIDDEN_REQUEST;
    }
    if (S_ISDIR(m_file_stat.st_mode)) {
        return BAD_REQUEST;
    }

    int fd = open(m_real_file, O_RDONLY);
    m_file_address = (char *)mmap(0, m_file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
    return FILE_REQUEST;
}
#endif
