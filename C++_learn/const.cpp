/*************************************************************************
	> File Name: const.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月09日 星期一 16时50分47秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    const int buf_size = 512;
    //buf_size = 512;    // 错误：试图向const对象写值

    //const int k;       // 错误：k是一个未初始化常量
    //buf_size++;        // 错误：buf_size是一个const常量

    int i = 42;
    const int ci1 = i;   // 正确：i的值被拷贝给了ci
    int j = ci1;         // 正确：ci的值被拷贝给了j
    
    // 如果想在多个文件中共享同一个const对象，必须在变量的定义之前添加extern关键字
    //extern const int buf_size2 = 512;
    

    // const的引用
    const int ci = 1024;
    const int &r1 = ci;  //正确：引用及其对象上都是常量
    //r1 = 42;             //错误：r1是对常量的引用
    //int &r2 = ci;        //错误：试图让一个非常量引用指向一个常量对象 
    //
    const int a = 1;
    const int *b = &a;
    
    vector<int> vec;
    const vector<int>::iterator iter = vec.begin();
    *iter = 10;
    //++iter;   错误! iter是const
    vector<int>::const_iterator cIter = vec.begin();
    //*cIter = 10;  错误：*cIter是const
    ++cIter;
}
