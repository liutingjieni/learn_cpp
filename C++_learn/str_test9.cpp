/*************************************************************************
	> File Name: str_test9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 16时03分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    string s_in;
    string s_out;
    cin >> s_in;
    for (auto c : s_in) {
        if (!ispunct(c)) {
            s_out = s_out + c;
        }
    }
    cout << s_out << endl;
}
