/*************************************************************************
	> File Name: init_list.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月15日 星期二 22时34分03秒
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

void func(vector<int> ls)
{
    int sum = 0;
    for (auto &i: ls) {
        i *= 2;
        sum += i;
    }
    cout << sum << endl;
}

void fund(initializer_list<int> ls)
{
    int sum = 0;
    for (auto i : ls) {
        sum += i;
    }
    cout << sum << endl;
}
int main()
{
    func({1,2,3,4});
    fund({1,6});
}
