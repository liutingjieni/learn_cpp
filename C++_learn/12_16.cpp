/*************************************************************************
	> File Name: 12_16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 20时56分10秒
 ************************************************************************/

#include<iostream>
#include<memory>
using namespace std;

int main()
{
    unique_ptr<int> q(new int);
    //unique_ptr<int> p = q;
    //unique_ptr<int> p(q);


    int *a = new int(2048);
    unique_ptr<int> b(a);
    *a = 1024;
    cout << *a << *b << endl;
    //double free
    //delete a;
    // cout << *a << *b << endl;

    //可以释放一个空指针nullptr
    int *c = nullptr;
    delete c;
}
