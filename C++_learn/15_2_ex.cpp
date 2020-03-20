/*************************************************************************
	> File Name: 15_2_ex.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年03月17日 星期二 23时25分15秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price) : 
                        bookNo(book), price(sales_price) { cout << "Quote init" << endl; }
    string isbn() const { return bookNo; }
    
    virtual double net_price(size_t n) const 
                        { return n * price; }
    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc) : 
                Quote(book, p), min_qty(qty), discount(disc) { cout << "init"; };

    double net_price(size_t) const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty) 
        return cnt * (1 - discount) * price;
    else 
        return cnt * price;
}

int main()
{
    Quote item;
    Bulk_quote bulk("qq", 2, 3, 0.4);
    cout << bulk.net_price(3);
    Quote *p = &item;
    p = &bulk;
    Quote &r = bulk;
}
