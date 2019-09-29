/*************************************************************************
	> File Name: iterator5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月29日 星期日 21时45分15秒
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int>  a(2),b;
    
    for (int i = 0; i < 2; i++) {
        a.push_back(i);
    }
    a[0] = 1;
    for (auto q = a.begin(); q != a.end(); q++) {
        cout << (*q) << endl;
    }
    // 为啥a &a &a[0]输出的地址值不一样
    // a是什么
    // a.begin()的类型是什么
    printf("a %p\n", a);
    printf("&a    %p\n", &a);
    printf("&a+1 %p\n",&a +1);
    printf("&a[0] %p\n", &a[0]);
    printf("a.begin() %p\n", a.begin());
    //printf("%p\n", a+1);
    printf("&a[0]+1 %p\n", &a[0] + 1);
    printf("a.begin()+1 %p\n", a.begin()+1);
}
