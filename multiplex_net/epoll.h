/*************************************************************************
	> File Name: Epoll.h
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月17日 星期五 09时46分13秒
 ************************************************************************/

#ifndef _EPOLL_H
#define _EPOLL_H
#include "socket.h"
#include "threadpool.h"
#define EPOLL_MAX 100000
#define LISTENAMX 1000
#include <sys/epoll.h> 
#include <unistd.h>

char pack[1000];

class Epoll {
public:
    Epoll(Socket fd);
    ~Epoll() {  }
    void active_fd();
    void deal();

private:
    void epoll_add_(int);
    void fd_read(int fd);
    
    int epoll_fd;
    struct epoll_event ev, events[EPOLL_MAX];
    int fd_num; //活跃的文件描述符数量
    Socket sock_fd;
    callback mess_callback_;
    Threadpool threadpool;

public:
    void set_mess_callback(callback  cb) {
        mess_callback_ = cb;
    }
};


Epoll::Epoll(Socket fd) : sock_fd(fd)
{
    epoll_fd = epoll_create(EPOLL_MAX);
    fd_read(sock_fd.get_fd());
    epoll_add_(sock_fd.get_fd());
}

void Epoll::fd_read(int fd)
{
    ev.data.fd = fd;
    ev.events = EPOLLIN;

}
void Epoll::epoll_add_(int fd)
{
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ev);
}

void Epoll::active_fd()
{
    fd_num = epoll_wait(epoll_fd, events, EPOLL_MAX, 1000);
}

void Epoll::deal()
{
    for (int i = 0; i < fd_num; i++) {
        if(events[i].data.fd == sock_fd.get_fd()) {
            sock_fd.accept_();
            fd_read(sock_fd.get_clifd());
            epoll_add_(sock_fd.get_clifd());
        }
        else if(events[i].events & EPOLLIN) {
            int ret = recv(events[i].data.fd, &pack, sizeof(pack) ,MSG_WAITALL);    
            if (ret <= 0) {
                close(events[i].data.fd);
                events[i].data.fd = -1;
            }
            threadpool.push_back(mess_callback_);
        }
    }
}

#endif
