/*************************************************************************
	> File Name: type2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 13时18分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    //赋值是会产生引用的一种典型表达式，引用的类型就是左值的类型
    //a 是int类型，则表达式i = x的类型是int& ,引用类型
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a; 
    cout << c << "  " << d << endl;
    d = 1;
    cout << c << "  "<< a << "  " << d << endl;
}
