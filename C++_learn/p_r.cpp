/*************************************************************************
	> File Name: p_r.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月09日 星期一 09时24分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int i = 42;
    int *p;
    int *&r = p;         //r是一个对指针p的引用

    r = &i;
    *p = 1;

    cout << i << endl;
    *r = 0;
    cout << i << endl;

}
