/*************************************************************************
	> File Name: String.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 11时41分08秒
 ************************************************************************/

#include "string.h"
#include <iostream>
using namespace std;
int main()
{
    String s("abc");
    cout << s.size() << endl;
    cout << s  << s.size() << endl;

    String s1(s);
    cout << s1 << s1.size() << endl;
    
    String s2(10,'a');
    cout << s2 << s2.size() << endl;
    
    
    s2 = s1;
    cout << s2 << s2.size() << endl;
    const char *t = "123";
    s2 = t;
    cout << s2 << s2.size() << endl;
    
    String s3(t);
    cout << s3 << s3.size() << endl;
    
    String s4, s5;
  //  cin >> s4 >>s5;
   // cout << s4 << s4.size() << endl;
  //  cout << s5 << s5.size() << endl;

    cout << s[1] << s[2] << endl;

    cout << s4.size() << s5.size() << endl;
    String s6;
    s6 = (s4 + s5);
    cout << s6 << endl;
    
    s6 = s6 + "world";
    cout << s6 << s6.size() << endl;
    s6 = "world" + s6;
    cout << s6 << s6.size() << endl;
    s6 = s6 + "world" + s5;
    cout << s6 << s6.size() << endl;

    String s7 = "456";
    s2 = "456";
    s3 = "12";
    s4 = "454";
    cout << (s7 == s2) << endl;
    cout << (s7 == s3) << endl;
    cout << (s7 == s4) << endl;

    const char *t1 = "qwe";
    s1 = "qwe";
    cout << (s1 == t1) << endl;
    cout << (t1 == s1) << endl;
    s1 = "abc";
    cout << (s1 == t1) << endl;
    cout << (t1 == s1) << endl;
    cout << (s1 > t1) << endl;
    cout << (s1 < t1) << endl;
    cout << (s1 >= t1) << endl;
    cout << (s1 <= t1) << endl;
    
    cout << s1 << s2 << endl;
    s1.swap(s2);
    cout << s1 << s2 << endl;
    swap(s1, s2);
    cout << s1 << s2 << endl;
    
    s1.push_back('A');
    cout << s1 << s1.size() << endl;
    s1.push_front('A');
    cout << s1 << s1.size() << endl;

    s1.push_back(36);
    cout << s1 << s1.size() << endl;
    s1.push_front(36);
    cout << s1 << s1.size() << endl;

    Iterator tp = s1.insert(s1.begin() + 1, 'W');
    cout <<s1 << s1.size() <<endl;
    auto tp1 = s1.insert(s1.begin(), 3, 'B');
    cout <<s1 << s1.size() << endl;
    cout << s2 << s2.size() << endl;
    
    auto tp2 = s1.insert(s1.begin()+2, s2.begin(), s2.end());
    cout << s1 << " "<< s1.size() << endl;
    
    s1.pop_back();
    cout << s1 << " "<< s1.size() << endl;
    s1.pop_front();
    cout << s1 << s1.size() << endl;
}


