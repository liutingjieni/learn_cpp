/*************************************************************************
	> File Name: 3.37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月07日 星期一 19时23分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    const char ca[] = {'h','e','l','l','o'};
    const char *cp = ca;
    while(*cp) {
        cout << *cp << endl;
        ++cp;
    }
}
