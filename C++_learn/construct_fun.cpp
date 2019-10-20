/*************************************************************************
	> File Name: construct_fun.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月18日 星期五 22时05分36秒
 ************************************************************************/

#include<iostream>
#include"Sales_data.h"
using namespace std;

int main()
{
    Sales_data data1;
    Sales_data data2("978-7-121");
    Sales_data data3("978-7-121", 100, 128, 109);
    Sales_data data4(cin);
    cout << "书籍的销售情况是：" << endl;
    cout << data1.bookNo << endl;
    cout << data2.bookNo << endl;
    cout << data3.bookNo << endl;
    cout << data4.bookNo << endl;
    return 0;

}


