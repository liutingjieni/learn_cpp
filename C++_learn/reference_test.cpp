/*************************************************************************
	> File Name: reference_test.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月18日 星期三 22时24分04秒
 ************************************************************************/

#include <iostream>
using namespace std;

void test(const int &i)
{
    printf("%d %p\n", i, &i);
}

int main()
{
    int i = 0;
    int &r = i;
    printf("%d %p\n", i, &i);
    printf("%d %p\n", r, &r);
    test(i);
}
