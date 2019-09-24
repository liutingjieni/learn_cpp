/*************************************************************************
	> File Name: str_test3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月24日 星期二 22时55分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int i = 0;
    string str, str1;
    while((cin >> str) and i < 10) {
        str1 = str1 + str + ' ';
        i++;
    }
    cout << str1 << endl;
}
