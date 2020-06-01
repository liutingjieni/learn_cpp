/*************************************************************************
	> File Name: virtual.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年06月01日 星期一 15时39分00秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Tmp {
public:
    //声明一个构造函数,编译器不再为它创建default构造函数
    Tmp(int xt, int yt) : x(xt), y(yt) {  }
    //实现virtual函数,对象必须携带某些信息,主要用来在运行期决定哪一个virtual函数该被调用.
    //该信息通常有一个所谓的vptr(virtual table pointer)指针指出
    virtual ~Tmp() {  } 
    virtual int test() {  }
private:
    int x;
    int y;
};

int main()
{
    Tmp t(1, 2);
    cout << sizeof(t) << endl;
}
