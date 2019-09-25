/*************************************************************************
	> File Name: vector.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 16时20分09秒
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    int i = 0;
    while (cin >> n && n != 0) {
        v.push_back(n);
        i++;
    }
    int flag = i;
    while (i--) {
        cout << v[flag - i - 1] << " ";
    }
    cout << endl;
}
