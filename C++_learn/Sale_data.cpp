/*************************************************************************
	> File Name: Sale_data.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月25日 星期三 17时50分26秒
 ************************************************************************/

#include <iostream>
using namespace std;

class sales_data {
public:
    sales_data() {  };
    sales_data(const int &t1, const int &t2):price(t1), discount(t2) {  }
    
private:
    int price;
    int discount;
};

template <typename T> 
bool compare(const T &v1, const T &v2)
{
    if (v1 < v2) return 1;
    else if (v1 > v2) return -2;
    return 0;
}


int main()
{
    sales_data c();
    sales_data a(1, 0.8);

    sales_data b(4, 0.7);
    int x = 0, y = 1;
    int t = compare(x, y);
    cout << t << endl;
}
