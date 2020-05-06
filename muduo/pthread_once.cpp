/*************************************************************************
	> File Name: pthread_once.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年05月05日 星期二 23时14分07秒
 ************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

pthread_once_t once = PTHREAD_ONCE_INIT;
pthread_t tid;

void thread_init()
{
        printf("I'm in thread 0x%x\n", tid);

}


void *thread_fun1(void *arg)
{
        tid = pthread_self();
        printf("I'm thread 0x%x\n", tid);
        printf("once is %d\n", once);
        pthread_once(&once, thread_init);
        printf("once is %d\n", once);

        return NULL;

}

void *thread_fun2(void *arg)
{
        sleep(2);
        tid = pthread_self();
        printf("I'm thread 0x%x\n", tid);
        pthread_once(&once, thread_init);

        return NULL;

}

int main()
{
        pthread_t tid1, tid2;
        int err;

        err = pthread_create(&tid1, NULL, thread_fun1, NULL);
        if(err != 0)
    {
                printf("create new thread 1 failed\n");
                return 0;
            
    }
        err = pthread_create(&tid2, NULL, thread_fun2, NULL);
        if(err != 0)
    {
                printf("create new thread 1 failed\n");
                return 0;
            
    }


        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);

        return 0;
}
