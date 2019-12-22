/*************************************************************************
	> File Name: template.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月20日 星期五 23时07分43秒
 ************************************************************************/

#include <iostream>
using namespace std;

// 在模板参数列表中,typename和class没有什么不同
template <typename T, class W>
int compare(const T &v1, const T &v2, const W w)
{
    //类型参数可以用来指定返回类型或函数的参数类型
    //以及在函数体用于变量声明或类型转换
    T tmp = v1 * v2 ;
    cout << tmp << endl << 2 * w << endl;
    if (less<T>() (v2, v1)) {return -1;}
    else if (less<T>() (v1, v2)) {return 1;}
    return 0;
}

int main()
{
    int a = 1, b = 2;
    cout << compare(a, b , 2.2) << endl;
}

//实例化:当调用一个函数模板时,编译器会利用给定的函数实参来推断模板实参,用此实际实参代替模板参数来创建出模板的一个新的"实例",也就是一个真正可以调用的函数,这个过程称为"实例化"
//
