/*************************************************************************
	> File Name: 14_7.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月12日 星期四 17时54分49秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Strin {
public:
    Strin() {};
    Strin(const char *st):str(st){  }
    friend ostream &operator<<(ostream &os, const Strin & sr);
private:
    const char *str;
};

ostream &operator<<(ostream &os, const Strin & sr)
{
            cout << sr.str;

        
}

int main()
{
    Strin s;
    Strin s1("hello");
    s = s1;
    cout << s1 << s << endl;
}
