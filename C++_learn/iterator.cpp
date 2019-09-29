/*************************************************************************
	> File Name: iterator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月29日 星期日 13时59分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    string s("some string");
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << s << endl;

    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
        *it = toupper(*it);
    }
    cout << s << endl;
}
