/*************************************************************************
	> File Name: string_for.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月24日 星期二 23时12分55秒
 ************************************************************************/

#include<iostream>
#include <cctype>
using namespace std;

int main()
{
    string str("some string");
    for(auto c : str) {
        cout << c << endl;
    }

    string s("hello world!!!");
    decltype(s.size()) punct_cnt = 0;
    for(auto c :s) {
        if(ispunct(c)) {
            ++punct_cnt;
        }
    }
    cout << punct_cnt << " punctuation charasters in " << s << endl;
}
