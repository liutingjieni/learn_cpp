/*************************************************************************
	> File Name: sizeof_t.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月09日 星期三 19时43分15秒
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

int main()
{
    //输出的值是一样的，他的存储方式？？？
    vector<string> s;
    vector<string> v1(10);
    vector<int>   i;
    cout << sizeof(s) << endl;
    cout << sizeof(i) << endl;
    cout << sizeof(v1) << endl;
}
