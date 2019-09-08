/*************************************************************************
	> File Name: var_init.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月08日 星期日 14时28分10秒
 ************************************************************************/

#include <iostream>
using namespace std;

string global_str;
int global_int;

int main()
{
    int local_int;
    string local_str;
    //string类默认规定如果没有指定初值则生成一个空串
    cout << global_str << endl;
    //定义为任何函数之外的变量被初始化为0 
    cout << global_int << endl;
    cout << local_str << endl;
    cout << local_int << endl;
    //int i = { 3.14 };
    //内置类型的变量，如果我们使用列表初始化且初始化存在丢失信息的风险，则编译器报错。
    int i = 3.14;
    cout << i << endl;
    //i的输出值为3;

}
