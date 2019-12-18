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
    test(int it, double bt) : i(it), b(bt), s("asd") {  }
    test(int it, double bt, const string &st) : i(it), b(bt), s(st)  
    {   
        cout << i << b << s << endl;
    }
    void print();
private:
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
    auto q = p;
    p->print();

    test t(3, 4, "qww");
    t.print();
    
    test t1(3, 4);
    t1.print();

    test w;
    w.print();
}
