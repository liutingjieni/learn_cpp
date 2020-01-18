/*************************************************************************
	> File Name: 13_13.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 00时38分30秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct X {
    X() { cout << "x()" << endl; }
    X(const X&) { cout << "x(const x&)" << endl; }
    X& operator=(const X &t) {cout << "拷贝赋值运算符 = (const x&)" << endl; return *this; }
    ~X() { cout << "析构函数~x()" << endl; }
};


void f1(const X &x) {  }
void f2(X x){  }
int main()
{
    X x1;
    //X *x2; // 不调用构造函数,析构函数
    //X *x3(new X); //调用构造函数
    //delete x3;//调用析构函数
    //X x4(x1);

    //vector<X> x5;
    //vector<X> x6(10); 

    X x7 = x1; //拷贝构造函数
    
    X x8;
    x8 = x1;   //拷贝赋值运算符

    cout << "引用传递" << endl;
    f1(x1);
    cout << endl;

    cout << "非引用传递" << endl;
    f2(x1);
    cout << endl;

    cout << "动态分配" << endl;
    X *p1 = new X;
    delete p1;
    cout << endl;

    cout << "添加到容器中:" << endl;
    vector<X> vx;
    vx.push_back(x1);
    cout << endl;

}
