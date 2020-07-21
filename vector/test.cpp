/*************************************************************************
	> File Name: test.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月21日 星期二 23时29分41秒
 ************************************************************************/

#include <iostream>
#include "m_vector.h"
using namespace std;

int main()
{
    m_vector<int> t;
    m_vector<int> t2(3,10);
    m_vector<int> t1(t2);
    m_vector<int> t3(5);
    t3.push_back(11);
    t.push_back(12);
    t.push_back(12);
    m_vector<int> t4 = t;
    cout << *(t4.begin_()) <<*(t4.end_()) << endl;
    cout << (t == t4);
    cout << (t != t2);
    cout << (t > t4);
    cout << (t >= t4);
    cout << (t < t4);
    cout << (t <= t4);
    cout << t2.size() << endl;
    t2.insert(t2.begin_() + 1, 1);
    cout << t2.size() << endl;
    for(int i = 0; i < t2.size(); i++) {
        cout << "22222222222222 "<< t2[i] << endl;
    }
    t2.insert(t2.begin_() + 1,3, 2);
    for(int i = 0; i < t2.size(); i++) {
        cout << "22222222222222 "<< t2[i] << endl;
    }
    t2.insert(t2.begin_() + 1, t3.begin_(), t3.begin_()+2);
    for(int i = 0; i < t2.size(); i++) {
        cout << "3333333333333 "<< t2[i] << endl;
    }
    t2.erase(t2.begin_() + 1, t2.end_());
    for(int i = 0; i < t2.size(); i++) {
        cout << "  3333333333333 "<< t2[i] << endl;
    }

}
