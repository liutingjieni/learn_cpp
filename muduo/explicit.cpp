/*************************************************************************
	> File Name: explicit.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年05月07日 星期四 14时28分11秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Circle
{
public:
    explicit Circle(double r):R(r) {}
    explicit Circle(int x, int y = 0) : X(x), Y(y) {}
    explicit Circle(const Circle& c): R(c.R), X(c.X), Y(c.Y) {}
private:
    double R;
    int X;
    int Y;
};

int main()
{
    Circle A(1.23);
    //Circle B = 123;   无法调用
    Circle C(A);
    return 0;
}
