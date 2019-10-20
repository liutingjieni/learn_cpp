/*************************************************************************
	> File Name: for.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月15日 星期二 22时08分57秒
 ************************************************************************/

#include<iostream>
using namespace std;

void func(int (&a)[10])
{
    for (auto i : a) {
        cout << i << endl; 
    }
}

int main()
{
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    for (auto &i : a) {
        i *= i;
    }
    for (auto i : a) {
        cout << i << endl; 
    }
    func(a);
}
