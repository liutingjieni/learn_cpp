/*************************************************************************
	> File Name: conn.h
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月19日 星期一 18时53分41秒
 ************************************************************************/

#ifndef _CONN_H
#define _CONN_H
#include "buffer.h"
//保存客户端
class Conn {
public:
    Conn () {  }
    Conn(const Conn& t) 
        : fd(t.fd), addr(t.addr) {  }
    ~Conn() {}
    
    int fd;
    struct sockaddr_in addr;
    static socklen_t len;
};
socklen_t Conn::len = sizeof(struct sockaddr_in);

class connector {
public:
    connector() : conn_(new Conn), buffer_(new buffer) {  }
    int read(int fd);
    int connfd()
    {
        return conn_->fd;
    }
private:
    std::shared_ptr<Conn> conn_;
    std::shared_ptr<buffer> buffer_;
    int save_errno;
};

int connector::read(int fd)
{
    buffer_->read_fd(fd, &save_errno);
    return save_errno;
}

#endif
