/*************************************************************************
	> File Name: conversion.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年02月11日 星期二 02时29分03秒
 ************************************************************************/

#include <iostream>
using namespace std;

class SmallInt {
public:
    SmallInt(int i = 0) : val(i) 
    {
        if (i < 0 || i > 255)
            throw std::out_of_range("bad SmallInt value");
    }
    operator int () const { return val; }
private:
    size_t val;
};


int main()
{
    SmallInt si;
    si = 4;
    si + 3; //首先将si隐式地转换成int,然后执行整数的加法
}
