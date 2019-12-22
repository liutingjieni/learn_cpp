/*************************************************************************
	> File Name: op.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 16时57分10秒
 ************************************************************************/

#include <iostream>
using namespace std;

class book {
public:
    book(int a, int b, const string &s) : price(a), discount(b), isbn(s) {}
    int operator < (const book &b);

private:
    int price;
    int discount;
    string isbn;
};

int book::operator < (const book &b)
{
    return price > b.price ? -1: 1;
}

int main()
{
    book book1(12, 0.8, "lala");
    book book2(1, 0.7, "wq");
    int t = book1<book2;
    cout << t << endl;
}
