/*************************************************************************
	> File Name: func_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月16日 星期三 14时27分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

int *calc(int *);
double *calc(double *);

int main()
{
    int a = 0;
    double b = 1.1;
    cout << *calc(&a) << endl;
    cout << *calc(&b) << endl;
}

int *calc(int *a)
{
    return a;
}

double *calc(double *b)
{
    return b;
}
