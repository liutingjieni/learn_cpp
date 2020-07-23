/*************************************************************************
	> File Name: Epoll.h
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月17日 星期五 09时46分13秒
 ************************************************************************/

#ifndef _EPOLL_H
#define _EPOLL_H
#include "socket.h"
#define EPOLL_MAX 100000
#define LISTENAMX 1000
#include <sys/epoll.h> 

class Epoll {
public:
    typedef function<>

    Epoll(Socket fd);
    ~Epoll();
    void active_fd();
    void deal();

private:
    void epoll_add_(int);
    void fd_read(int fd);
    
    int epoll_fd;
    struct epoll_event ev, events[EPOLL_MAX];
    int fd_num; //活跃的文件描述符数量
    Socket sock_fd;
    char pack[1000];
};
#endif
