/*************************************************************************
	> File Name: str_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月24日 星期二 14时12分57秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    cout << s << endl;

    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << s2 << endl; 
    cout << s1 << s2 << endl; 

    // 执行完上两段执行这一段line中不能读入东西为空值 
    string line;
    getline(cin, line);  //
    cout << "line :" << line << "endl"<< endl;
    return 0;
}
