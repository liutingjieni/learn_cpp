/*************************************************************************
	> File Name: swap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月12日 星期六 22时53分12秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

// 指针
void swap_p(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;

}

// 引用
void swap_t(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

// 泛型编程
void swap_g(void *a, void *b, int size)
{
    void *t = malloc(size);
    memcpy(t, a, size);
    memcpy(a, b, size);
    memcpy(b, t, size);
}

int main()
{
    double a,b;
    cin >> a >> b;
    //swap_p(&a, &b);
    //swap_t(a, b);
    swap_g(&a, &b,sizeof(a));
    cout << a << " "<< b << endl;
}
