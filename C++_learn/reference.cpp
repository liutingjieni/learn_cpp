/*************************************************************************
	> File Name: reference.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月08日 星期日 21时33分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    //一旦初始化完成，引用将和他的初始化对象绑定在一起
    //引用类型的初始值必须是一个对象
    //int &rvall = 1.01;
    //无法令引用重新绑定在另一个对象，因此引用必须初始化
    //int &rvall;
    int ival = 1.01;
    int &rval2 = ival;
    cout << ival << endl;
    rval2 =2;
    cout << rval2  <<" " << ival << endl;

    int i = 0, &r1 = i;
    double d = 3.14159, &r2 = d;
    //r2 = 3.14159;
    //r2 = r1;
    i = r2;
    ///r1 = d;

    cout << i <<endl << r1 << endl << d <<endl << r2 << endl;
    
    //引用的类型要和与之绑定的对象严格搭配
    //而且，引用只能绑定在对象上，而不能与字面值或某个表达式的计算结果绑定在一起
    int t = 3;
    double dval = 3.14;
    //int &r = dval;
    int i1, &ri1 = i;
    i =5; 
    ri1 = 10;
    cout << i << " " << ri1 <<endl;
    // &i, &ri1 的输出结果是一样的，引用是为对象起了另一个名字，引用类型应用另一种类型
    cout << &i << endl;
    cout << &ri1 << endl;

}


