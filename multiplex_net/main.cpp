/*************************************************************************
	> File Name: main.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月17日 星期五 15时16分27秒
 ************************************************************************/

#include <iostream>
#include "epoll.h"
using namespace std;
using std::placeholders::_1;

void onmessage(shared_ptr<connector> connector_)
{
    printf("&&&&&&&&&&&&&%s\n ", pack);
    send(connector_->connfd(), &pack, strlen(pack), 0);
}

//void ontime(shared_ptr<Conn> conn)
//{
//    printf("on time\n");
//}

int main()
{
    Socket sockfd(8888);
    Epoll epoll(sockfd);
    epoll.set_mess_callback(bind(onmessage, _1));
    //epoll.set_time_callback(bind(ontime, _1));
    while(1) {
        epoll.active_fd();
        epoll.deal();
    }
}
