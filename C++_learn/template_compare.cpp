/*************************************************************************
	> File Name: template_compare.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年02月13日 星期四 02时16分31秒
 ************************************************************************/

#include <iostream>
using namespace std;

template <typename T>
void compare(const T &a, const T &b)
{
    cout << a * b << endl;
}

template <typename T, unsigned N>
void print(const T (&a)[N])
{
    for (size_t i = 0; i != N; i++) {
        cout << a[i] << endl;
    }
}
int main()
{
    compare(1, 2);
    compare('a', 'b');
    int a[10] = {1,2,3,4,5,6};
    print(a);
}
