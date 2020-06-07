/*************************************************************************
	> File Name: max_thread.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年06月07日 星期日 16时39分26秒
 ************************************************************************/

#include <pthread.h>
#include <stdio.h>

int a = 0;
void *thread_fun(void *arg)
{
    printf("%d\n", a++);
}

int main()
{
    pthread_t tid;
    while(1) {
        pthread_create(&tid, NULL, thread_fun, NULL);
    }
}


// linux32位机下最多508个线程
// linux64位机下最多32748线程
