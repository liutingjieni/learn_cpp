/*************************************************************************
	> File Name: 13_1_delete.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 00时04分06秒
 ************************************************************************/

#include <iostream>
using namespace std;

class NoDtor {
public:
    NoDtor();
    ~NoDtor() = delete;
};


int main()
{
    //NoDtor nd; 错误:NoDtor的析构函数是删除的
    NoDtor *p = new NoDtor();
    //delete p;  错误:NoDtor的析构函数是删除的
    //对于析构函数已删除的类型,不能定义该类型的变量或释放指向该类型动态分配对象的指针

}
