/*************************************************************************
	> File Name: EventLoop.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月10日 星期五 23时05分02秒
 ************************************************************************/

#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
using namespace std;

class EventLoop
{
public:
    EventLoop();
    ~EventLoop();

    void loop();

    bool isInloopThread() const { return 1;}
    void assertInLoopThread()
    {
        if (!isInloopThread()) {
        }
    }


private:

    bool looping_;
    const pid_t threadId_;
};

__thread EventLoop* t_loopInThisThread = 0;

EventLoop::EventLoop()
    : looping_(false),
      threadId_()
{
    cout << "EventLoop created " << this << " in thread " << threadId_ << endl;
    if (t_loopInThisThread)
    {
        cout << "Another EventLoop " << t_loopInThisThread 
             << " exists in this thread " << threadId_;
    }
    else 
    {
        t_loopInThisThread = this;
    }
}
EventLoop::~EventLoop()
{
    assert(!looping_);
    t_loopInThisThread = NULL;
}

void EventLoop::loop()
{
    assert(!looping_);
    assertInLoopThread();
    looping_ = true;
    
    cout << "EventLoop " << this << " stop looping" << endl;
    looping_ = false;
}

void *threadFunc(void *arg)
{
    EventLoop loop;
    loop.loop();
}

int main()
{
    printf("main(): pid = %d", getpid());
    EventLoop loop;
    
    pthread_t t;
    pthread_create(&t, NULL, threadFunc, NULL);
    loop.loop();
    sleep(2);
}
