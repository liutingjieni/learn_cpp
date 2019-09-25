/*************************************************************************
	> File Name: vector_str.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 16时48分14秒
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> s;
    string st;

    while (cin >> st && st != "0") {
        s.push_back(st);
    }

    int i = 0;
    while (s[i] != 0) {
        cout << s[i] << endl;
        i++;
    }

}
