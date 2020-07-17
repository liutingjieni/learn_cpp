/*************************************************************************
	> File Name: socket.h
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月17日 星期五 09时36分24秒
 ************************************************************************/

#ifndef _SOCKET_H
#define _SOCKET_

#define IP "0.0.0.0"
#include <netinet/in.h>

class Socket{
public:
    Socket(int port);
    Socket(const Socket &sockfd);
    ~Socket() {  }
    void accept_();
    void init(int);
    int get_fd() const { return sock_fd; }
    int get_clifd() const {return conn_fd; }

private:
    int sock_fd;
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(struct sockaddr_in);
    int conn_fd;
};
#endif
