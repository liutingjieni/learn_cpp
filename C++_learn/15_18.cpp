/*************************************************************************
	> File Name: 15_18.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月20日 星期五 22时19分31秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Base {
public:
    void pub_mem();
void memfcn(Base &b) { b = *this; }
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base {
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
    int f1() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
    int f1() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Prot_Derv {
    void memfcn(Base &b) { b = *this; }
};
    


int main()
{
    //派生类向基类转换的可访问性
    
    //只有当D公有的继承B时,用户代码才能使用派生类向基类的转换
    //如果D继承B的方式是受保护的或者私有的,则用户代码不能使用该转换
    //
    //不论D以什么方式继承B,D的成员函数和友元都能使用派生类向基类的转换
    //派生类向其直接基类的类型转换对于派生类的成员和友元来说永远是可访问的
    //
    //如果D继承B的方式是公有的或受保护的,则D的派生类成员和友元可以使用D向B的类型转换,反之,如果D是私有的,则不能使用
    //
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;

    Base *p = &d1;
    //只有当派生累公有地继承基类时,用户代码才能使用派生类向基类的转换
    //p2 = &d2;
    // p3 = &d3;
    //
    //p4 = &dd1;
    //p5 = &dd2;
    //p6 = &dd3;
}
