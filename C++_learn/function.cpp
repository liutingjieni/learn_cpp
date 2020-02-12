/*************************************************************************
	> File Name: function.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 23时36分18秒
 ************************************************************************/

#include <iostream>
#include <functional>
#include <map>
using namespace std;

int main()
{
    plus<int> a;
    cout << a(1, 2) << endl;

    function<int(int, int)> f1 = plus<int>(); 
    function<int(int, int)> f2 = divides<>(); 
    function<int(int, int)> f3 = [](int i, int j)
                                 { return i * j; }; 
    cout << f1(4, 2) << endl;
    cout << f2(4, 2) << endl;
    cout << f3(4, 2) << endl;

    map<string, function<int(int, int)>> bimops = {
        {"+", plus<>()},
        {"-", minus<>()},
        {"/", divides<>()},
        {"*", [](int i, int j) { return i * j; }},
        {"%", modulus<>()}
    };
    cout << bimops["+"](10, 5) << endl;
}
