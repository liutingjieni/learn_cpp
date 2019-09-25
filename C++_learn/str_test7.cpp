/*************************************************************************
	> File Name: str_test7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 15时45分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    string s;
    // 合法，被初始化为空字符串，s[0] = NULL = 0
    cout << s[0] << endl;
    // 不合法，
    cout << s[1] << endl;
}
