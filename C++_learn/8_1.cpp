/*************************************************************************
	> File Name: 8_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月25日 星期五 22时05分30秒
 ************************************************************************/

#include<iostream>
#include<stdexcept>
using namespace std;

istream& f(istream &in)
{
    int v;
    while (in >> v, !in.eof()) {
        if (in.bad()) {
            throw runtime_error("IO流错误");
        }
        if (in.fail()) {
            cerr << "数据错误，请重试：" << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main()
{
    cout << "请输入一些整数，按ctrl+z结束" << endl;
    f(cin);
    return 0;
}

