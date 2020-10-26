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

void onmessage(shared_ptr<conn> conn_)
{ 
    string s(conn_->read_buffer());
    const char *t = s.data();
    http *http_(new http(const_cast<char *>(t), s.size()));
    http_->process();
    cout << "onmessage" << t << endl;
    for(int i = 0; i < s.size(); i++) {
        cout << s[i];
    }
    cout << endl;
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
