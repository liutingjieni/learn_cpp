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
    int i = 0;

    while (cin >> st && st != "0") {
        s.push_back(st);
        i++;
    }

    int flag = i;
    while (i--) {
        cout << s[flag-i-1] << " ";
    }
    cout << endl;
    
   
}
