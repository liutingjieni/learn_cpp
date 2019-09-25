/*************************************************************************
	> File Name: vector_str2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 20时28分45秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> s;
    string st;
    while (cin >> st && st != "0") {
        for (auto &c : st) {
            c = toupper(c);
        }
        s.push_back(st);
    }

    int flag = s.size();
    for (int i = 0; i < flag; i++) {
        cout << s[i] << " ";
    }
} 
