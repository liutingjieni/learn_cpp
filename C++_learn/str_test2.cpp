/*************************************************************************
	> File Name: str_test2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月24日 星期二 22时19分29秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    string str1,str2;
    cin >> str1 >> str2;
    if (str1 > str2) {
        cout << str1 << endl;
    } 
    else if(str1 < str2) {
        cout << str2 << endl;
    }
    else {
        cout << str1 << " = " << str2 << endl;
    }
    
    if(str1.size() > str2.size()) {
        cout << str1 << endl;
    }
    else if (str1.size() < str2.size()) {
        cout << str2 << endl;
    }
    else {
        cout << str1 << " = " << str2 << endl;
    }
}
