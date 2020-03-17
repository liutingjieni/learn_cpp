/*************************************************************************
	> File Name: 15_ex.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年03月17日 星期二 15时17分48秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Quote {
public:
    string isbn() const;
    virtual double net_price(size_t) const;
};

class Bulk_quote : public Quote {
public:
}
