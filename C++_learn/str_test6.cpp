/*************************************************************************
	> File Name: str_test6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 15时39分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // 调用for循环更好，更简洁
    // while多调用了一个函数s.size()

    /*for (auto &c : s) {
        c = 'X';
    }*/

    auto i = s.size();
    while(i--) {
        s[i] = 'X';
    }
    cout << s << endl;
}

