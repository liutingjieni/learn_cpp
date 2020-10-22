/*************************************************************************
	> File Name: conn.h
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月19日 星期一 18时53分41秒
 ************************************************************************/

#ifndef _CONN_H
#define _CONN_H
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
std::map<int, std::shared_ptr<Conn>> conn_list;  //保存所有的连接信息

#endif
