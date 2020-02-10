/*************************************************************************
	> File Name: 函数调用.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年02月11日 星期二 02时07分24秒
 ************************************************************************/

#include <iostream>
using namespace std;

class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' ') :
    os(o), sep(c) {  }
    void operator()(const string &s) const { os << s << sep; }
private:
    ostream &os;
    char sep;
};

int main()
{
    PrintString printer;
    printer("s");
    PrintString errors(cerr, '\n');
    errors("s");
}
