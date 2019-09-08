/*************************************************************************
	> File Name: diff_un_signed.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月07日 星期六 17时58分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    unsigned u = 10, u2 = 42;
    cout << "u2 - u = " << u2 - u << endl;
    cout << u - u2 << endl;

    int i = 10, i2 = 42;
    cout << i2 - i << endl;
    cout << i - i2 << endl;
    cout << i - u2 << endl;
    cout << u2 - i << endl;
}
