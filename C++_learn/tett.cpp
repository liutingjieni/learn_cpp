/*************************************************************************
	> File Name: tett.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月10日 星期二 22时52分48秒
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class test {
public:
    test() {};
    test(int it, double bt, const string &st) : i(it), b(bt), s(st)  
    {   
        cout << i << b << s << endl;
        cout << "haha" << endl; 
    }
    void print();
public:
    int i = 2;
    double b = 2;
    string s = "@@@@";
};

void test::print()
{
    cout << i << b << s << endl;
}
int main()
{
    shared_ptr<test> p = make_shared<test>(4, 5, "ltlt");
    cout << "****" << p->i << endl;
    auto q = p;
    p->print();
    cout << q->i << endl;

    test t(3, 4, "qww");
    t.print();

    test w;
    w.print();
}
