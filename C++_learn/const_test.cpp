/*************************************************************************
	> File Name: const_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月24日 星期二 11时41分01秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    // 常量引用不能通过引用改变对象的值，
    // 而没有规定那个对象的值不能通过其他途径改变
    int i = 3;
    const int &r = i;    
    cout << r << endl;
    i = 4;
    cout << r << endl;

    // 指向常量的指针也没有规定其所指的对象必须是一个常量
    // 所谓指向常量的指针仅仅要求不能通过该指针改变对象的值
    // 而没有规定那个对象的值不能通过其他途径改变
    int pi = 1;
    const int * pip = &pi;
    cout << *pip << endl;
    pi = 2;
    cout << *pip << endl;
    //*pip = 3;        错误：不能改变所指向对象的值
    pip = &i;
    cout << *pip << endl;

    int pi2 = 3;
    int *const  pip2 = &pi2;
    cout << *pip2 << endl;
    *pip2 = 4;
    //pip2 = &pi;      错误：不能改变pip2 的值，即所指向的对象
    cout << *pip2 << endl;
   
    //const int ic;    错误：ic是一个未初始化的常量
    //int *const cp;   错误：cp的值是const常量，但是并未初始化
    const int * cp;
}

