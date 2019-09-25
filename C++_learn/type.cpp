/*************************************************************************
	> File Name: type.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 13时11分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    cout << c << endl;
    cout << d << endl;

    int x = 5, &y = x;
    cout << x << "  " << y << endl;
    x++;
    cout << x << "  " << y << endl;
    cout << &x << "  " << &y << endl;

}
