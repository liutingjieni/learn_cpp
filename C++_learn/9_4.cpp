/*************************************************************************
	> File Name: 9_4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月30日 星期三 22时02分56秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int>::iterator search_vec(vector<int>::iterator beg,  auto end, int val)
{
    for (;beg != end; beg++) {
        if (*beg == val) {
            return beg;
        }
    }
    return end;
}

int main()
{
    vector<int> ilist = {1, 2, 3, 4, 5, 6, 7};

    cout << *(search_vec(ilist.begin(), ilist.end(), 3)) << endl;
    cout << *(search_vec(ilist.begin(), ilist.end(), 8)) << endl;
}
