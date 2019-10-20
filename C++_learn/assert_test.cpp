/*************************************************************************
	> File Name: assert_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月16日 星期三 19时12分41秒
 ************************************************************************/

#include<stdio.h>
#define NDEBUG
#include <assert.h>
using namespace std;

int main(){
    int m, n, result;
    scanf("%d %d", &m, &n);
    assert(n != 0); 
    result = m / n;
    printf("%d\n",result);
    return 0;
}
