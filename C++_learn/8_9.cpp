/*************************************************************************
	> File Name: 8_9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月26日 星期六 16时32分10秒
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
#include<stdexcept>
using namespace std;

istream & f(istream & in)
{
    string v;
    while (in >> v, !in.eof()) {
        if (in.bad()) {
            throw runtime_error("IO流错误");
        }
        if (in.fail()) {
            cerr << "数据错误，请重试" << endl;
           // in.clear();
            //in.ignore();
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main()
{
    ostringstream msg;
    msg << "C++ Primer 第五版" << endl;
    istringstream in(msg.str());
    f(in);
    return 0;
}
