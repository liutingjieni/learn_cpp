/*************************************************************************
	> File Name: str_test4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 15时23分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    string s("Hello world!!!");

    // 如果想改变string对象中的字符的值，必须把循环变量定义成引用类型
    for (auto &c : s) {
        c = toupper(c);
        cout << c << endl;
    }
    cout << s <<endl;
}
