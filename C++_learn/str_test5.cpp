/*************************************************************************
	> File Name: str_test5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 15时30分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    string s("some string");
    if (!s.empty()) {
        s[0] = toupper(s[0]);
        auto &c = s[1];
        c = toupper(c);
    }

    cout << s << endl;
}
