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
#include "timer_wheel.h"
#include "conn.h"
using std::placeholders::_1;

int setnonblocking(int fd)
{
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

void ontime(std::shared_ptr<conn> conn)
{
    printf("on time\n");
    close(conn->get_fd());
    conn_list.erase(conn->get_fd());

}

class Epoll {
public:
    Epoll(Socket fd);
    ~Epoll() {  }
    void active_fd();
    void deal();

    void fd_write(int fd);
    void fd_read(int fd);
    void epoll_mod_(int);
private:
    void epoll_add_(int);
    void epoll_del_(int);
    
    int epoll_fd;
    struct epoll_event ev, events[EPOLL_MAX];
    int fd_num; //活跃的文件描述符数量
    Socket sock_fd;
    Task task_; //task分配空间, 传给线程池的队列
    Threadpool threadpool;
    Timer timer;
    time_wheel wheel;
    
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
    //fd_read(timer.get_fd());
    //epoll_add_(timer.get_fd());
}


void Epoll::fd_read(int fd)
{
    ev.data.fd = fd;
    ev.events = EPOLLIN;
}

void Epoll::fd_write(int fd)
{
    ev.data.fd = fd;
    ev.events = EPOLLOUT;
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

void Epoll::epoll_mod_(int fd)
{
    epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd, &ev);
}

void Epoll::active_fd()
{
    fd_num = epoll_wait(epoll_fd, events, EPOLL_MAX, 1000);
}

void Epoll::deal()
{
    char buf[10];
    for (int i = 0; i < fd_num; i++) {
        if(events[i].data.fd == sock_fd.get_fd()) {
            int conn_fd = sock_fd.accept_();
            fd_read(conn_fd);
            epoll_add_(conn_fd);

            //在时间轮上为新的连接加tw_timer
            //tw_timer *tw = wheel.add_timer(conn_list[conn_fd], 60);
            //为每个到时的连接添加回调函数
            //tw->set_time_callback(bind(ontime, _1));
        }
        // 定时器
        else if (events[i].events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR)) {
            cout << "EPOLLERR" << endl;
            epoll_del_(events[i].data.fd);
            close(events[i].data.fd);
            conn_list.erase(events[i].data.fd);
        }
        else if(events[i].events & EPOLLIN) {
            cout << "EPOLLIN" << endl;
            //定时器事件
            if (events[i].data.fd == timer.get_fd()) {
                read(timer.get_fd(), buf, sizeof(buf));
                wheel.tick(); //心跳事件到达
                
                timer.reset(); //定时器重新设置时间
            } 
            //收到包
            else {
                //根据到达连接的fd信息, 找到对应的conn
                shared_ptr<conn> conn = conn_list[events[i].data.fd];
                int ret = conn->read();  
               // if (ret < 0) {  
               //     cout << "ret < 0" << endl;
               //     close(events[i].data.fd);
               //     conn_list.erase(events[i].data.fd);
               //     events[i].data.fd = -1;
               //     continue;
               // }
                //根据conn的信息在map中找到对应tw_timer, 然后更新他在时间轮上的位置
                //wheel.update_timer(conn, 60);

                //在conn_list(所有连接map)找到所对应根据key(fd) 
                task_.conn_ = conn;
                threadpool.push_back(task_);
            }
        }
        else if (events[i].events & EPOLLOUT) {
            cout << "EPOLLOUT" << endl;
            //shared_ptr<conn> conn = conn_list[events[i].data.fd];
            //string s(conn->read_buffer());
            //const char *data = s.data();
            //write(events[i].data.fd, data, 1000);
        }
    }
}

#endif
