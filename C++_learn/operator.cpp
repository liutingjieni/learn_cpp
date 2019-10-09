/*************************************************************************
	> File Name: operator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月09日 星期三 18时40分43秒
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> iter;
    iter.push_back("hello1");
    iter.push_back("hello2");
    iter.push_back("hello3");
    cout << *iter.begin() << endl;
    cout << *(iter.begin() + 1)<< endl;
    cout << iter.empty() << endl;  
}
