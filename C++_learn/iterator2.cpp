/*************************************************************************
	> File Name: iterator2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月29日 星期日 19时31分04秒
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vi;

    for (int i = 0; i < 10; i++) {
        int a;
        cin >> a;
        vi.push_back(a);
    }
    for (auto it= vi.begin(); it != vi.end(); it++) {
        *it = *it * 2;
        cout << *it << endl;
    }
}
