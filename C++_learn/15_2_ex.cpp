/*************************************************************************
	> File Name: 15_2_ex.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年03月17日 星期二 23时25分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <memory>
#include <set>
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
double print_total(ostream &os, Quote &s, size_t num)
    { os  << s.net_price(num) << endl; }

class Basket {
public:
    void add_item(const shared_ptr<Quote> &sale) 
                { items.insert(sale); }
    double total_receipt(ostream &) const;
private:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs)
                { return lhs->isbn() < rhs->isbn(); }
    multiset<shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); 
              iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale:" << sum << endl;
    return sum;
};

int main()
{
    Quote item;
    Bulk_quote bulk("qq", 2, 3, 0.4);
    cout << bulk.net_price(3);
    Quote *p = &item;
    p = &bulk;
    Quote &r = bulk;

}
