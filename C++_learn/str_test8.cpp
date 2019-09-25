/*************************************************************************
	> File Name: str_test8.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 15时48分23秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    const string hexdigits = "0123456789abcdef";
    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished:"
         << endl;
    string result;
    string :: size_type n;
    while (cin >> n && n < 16) {
        if (n < hexdigits.size()) {
            result += hexdigits[n];
        }
    }

    cout << "Your hex number is: " << result << endl;
}
