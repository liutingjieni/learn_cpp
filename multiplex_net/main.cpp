/*************************************************************************
	> File Name: main.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月17日 星期五 15时16分27秒
 ************************************************************************/

#include <iostream>
#include "epoll.h"
using namespace std;



void onmessage(void)
{
    printf("%s\n ", pack);
}

int main()
{
    Socket sockfd(8888);
    Epoll epoll(sockfd);
    epoll.set_mess_callback(bind(onmessage));
    while(1) {
        epoll.active_fd();
        epoll.deal();
    }
}
