/*************************************************************************
	> File Name: 15_3.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月20日 星期五 17时46分20秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
              bookNo(book), price(sales_price) {  }
    string isbn() const { return bookNo; };
    virtual double net_price(size_t n) const { return n * price; };
    virtual void debug() const { cout << "bookNo " << bookNo << " price " << price << endl;}
    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote:public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double sales_price, 
         size_t min, double dis) : 
        Quote(book, sales_price), min_qty(min), discount(dis) {  }

    double net_price(size_t) const override;
    void debug() const 
    {
        Quote::debug();
        cout << "min_qty " << min_qty << "discount " << discount << endl; 
    }
private:
    size_t min_qty = 0;
    double discount = 0.0;

};

double Bulk_quote:: net_price(size_t book) const
{
    cout << " *****" << endl;
    
    if(book > min_qty) {
        return book * price * discount;
    }
    else {
        return book *price;
    }
}


double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN:" << item.isbn() << "# sold: " << ret << endl;
}

int main()
{
    Bulk_quote item("qw", 12, 3, 0.8);
    print_total(cout, item, 4);
    Quote item2("qw", 3);
    print_total(cout, item2, 4);
    item.debug();
    item2.debug();
    //静态绑定,对对象进行绑定,拷贝赋值
    Quote item3 = item;
    item3.debug();
    Quote item4(item);
    item4.debug();
    //动态绑定
    Quote* item5 = &item;
    item5->debug();
}
