/*************************************************************************
	> File Name: Epoll.h
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月17日 星期五 09时46分13秒
 ************************************************************************/

#ifndef _EPOLL_H
#define _EPOLL_H
#include "threadpool.h"
#define EPOLL_MAX 100000
#define LISTENAMX 1000
#include <sys/epoll.h> 
#include <unistd.h>
#include <fcntl.h>
#include "timer.h"
char pack[100];

int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

class Epoll {
public:
    Epoll(Socket fd);
    ~Epoll() {  }
    void active_fd();
    void deal();

private:
    void epoll_add_(int);
    void epoll_del_(int);
    void fd_read(int fd);
    
    int epoll_fd;
    struct epoll_event ev, events[EPOLL_MAX];
    int fd_num; //活跃的文件描述符数量
    Socket sock_fd;
    Task  task_;
    Threadpool threadpool;
    Timer timer;
    
public:
    void set_mess_callback(callback  cb) {
        task_.callback_ = cb;
    }
};


Epoll::Epoll(Socket fd) : sock_fd(fd)
{
    epoll_fd = epoll_create(EPOLL_MAX);
    fd_read(sock_fd.get_fd());
    epoll_add_(sock_fd.get_fd());
    fd_read(timer.get_fd());
    epoll_add_(timer.get_fd());
    printf("epoll init end\n");
}


void Epoll::fd_read(int fd)
{
    ev.data.fd = fd;
    ev.events = EPOLLIN;

}
void Epoll::epoll_add_(int fd)
{
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ev);
    setnonblocking(fd);  
}

void Epoll::epoll_del_(int fd)
{
    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, &ev);
}

void Epoll::active_fd()
{
    fd_num = epoll_wait(epoll_fd, events, EPOLL_MAX, 1000);
}

void Epoll::deal()
{
    for (int i = 0; i < fd_num; i++) {
        if(events[i].data.fd == sock_fd.get_fd()) {
            int conn_fd = sock_fd.accept_();
            fd_read(conn_fd);
            epoll_add_(conn_fd);
        }
        // 定时器
        else if (events[i].data.fd == timer.get_fd()) {
            epoll_del_(timer.get_fd());
            timer.reset(); //定时器重新设置时间
            epoll_add_(timer.get_fd());

        }
        else if(events[i].events & EPOLLIN) {
            int ret = recv(events[i].data.fd, &pack, sizeof(pack) ,MSG_WAITALL);   
            if (ret <= 0) {
                close(events[i].data.fd);
                events[i].data.fd = -1;
                //conn_list.earse(events[i].data.fd);
                
            }
            //在conn_list(所有连接map)找到所对应根据key(fd) 
            Conn conn = sock_fd.find(events[i].data.fd);
            task_.conn = conn;
            threadpool.push_back(task_);
        }
    }
}

#endif
