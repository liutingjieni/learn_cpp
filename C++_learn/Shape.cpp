/*************************************************************************
	> File Name: Shape.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 11时00分48秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

class Shape {
public:
    virtual double area() {  }
private:
    int x;
    int y;
};

class Circle : public Shape {
public:
    double area() {  }
};

class Triangle : public Shape {
public:
    double area() {  }
};

class Manage {
    Shape *a[100];
public:
    Manage(const Manage &m);
};

Manage::Manage(const Manage &m)
{
    for (int i = 0; i < 100; i++) {
        a[i] = new Shape;
        memcpy(a[i], m.a[i], sizeof(Shape));
    }
}

int main()
{
    
}
