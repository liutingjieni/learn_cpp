/*************************************************************************
	> File Name: test.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 11时39分01秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << s.size() << endl;
    s = "abc";
    cout << s.size() << endl;

    string s1(10, 'a');
    cout << s1 << s1.size() << endl;

    const char *t = "lt";
    string s3 = t;
    cout << t << s3 << endl;
    s3 = "qwe";
    cout << t << s3 << endl;
    t = "zxc";
    cout << t << s3 << endl;

    string s4;
   // cin >> s4;
   // cout << s4 << s4.size() <<endl;
    //cin >> s4;
   // cout << s4 << s4.size() << endl;

    const char *t1 = "qwe";
    s4 = "123";
    cout << (t1==s4) << endl;
    
    cout << (t1 < s4) << endl;
    cout << (s < s4) << endl;
    cout << (t1 < s1) << endl;
    
    string s5("ab");
    string s6("c");
    cout << (s5 < s6) << endl;
    
    cout << (1 >= 2) << endl;

        s1 = "qwe";
        cout << (s1 == t1) << endl;
        cout << (t1 == s1) << endl;
        s1 = "ab";
        cout << (s1 == t1) << endl;
        cout << (t1 == s1) << endl;
        cout << (s1 > t1) << endl;
        cout << (s1 < t1) << endl;
        cout << (s1 >= t1) << endl;
        cout << (s1 <= t1) << endl;

    cout << s1 << " " << s3 << endl;
    s1.swap(s3);
    cout << s1 << " " << s3 << endl;

    s1.push_back(36);
    cout << s1 << endl;;

    auto p = s1.insert(s1.end(),'1');
    cout << *p << s1 << endl;
   
    int i = s1.find('A');
    cout << i << s1[i] << endl;
}
