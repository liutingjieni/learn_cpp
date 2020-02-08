/*************************************************************************
	> File Name: HasPtr.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年02月09日 星期日 00时48分18秒
 ************************************************************************/

#include <iostream>
using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) { cout << "init" << endl; }
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) {  }
    HasPtr& operator=(const HasPtr &);
    ~HasPtr() {delete ps;}
private:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
}

int main()
{
    HasPtr a;
    HasPtr b("QQQ");
    HasPtr c(b);

}
