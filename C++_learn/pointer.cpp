/*************************************************************************
	> File Name: pointer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月08日 星期日 22时18分37秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    double dval;
    double *pd = &dval;
    double *pd2 = pd;
    
    //指针pi的类型和pd的类型不匹配
    //int *pi = pd;
    //试图把double型的对象的地址赋给int型的指针
    //pi = &dval;
    
    //初始化为空指针
    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;

    int* pi1, pi2; //p1是指向int的指针， p2是int
}
