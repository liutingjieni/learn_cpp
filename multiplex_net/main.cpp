/*************************************************************************
	> File Name: main.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月17日 星期五 15时16分27秒
 ************************************************************************/

#include <iostream>
#include "epoll.h"
#include <string.h>
#include "http.h"
using namespace std;
using std::placeholders::_1;

Socket sockfd(8888);
Epoll epoll(sockfd);

void onmessage(shared_ptr<conn> conn_)
{ 
    http *http_(new http(conn_));
    if(http_->process()) {
        epoll.fd_write(conn_->get_fd()); 
        epoll.epoll_mod_(conn_->get_fd());
    }
}

//void ontime(shared_ptr<Conn> conn)
//{
//    printf("on time\n");
//}

int main()
{
    epoll.set_mess_callback(bind(onmessage, _1));
    //epoll.set_time_callback(bind(ontime, _1));
    while(1) {
        epoll.active_fd();
        epoll.deal();
    }
}
