/*************************************************************************
	> File Name: lambda.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年02月12日 星期三 22时51分39秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class shorterString {
public:
    bool operator() (const string &s1, const string & s2) const 
    { 
        cout << "函数调用运算符" << endl; 
        return s1.size() > s2.size();
    }
};

int main()
{
    string s1("abc");
    string s2("a");
    shorterString t;
    cout << t(s1, s2) << endl;
   
    vector<string> words = {"a", "cba", "bc"};
    stable_sort(words.begin(), words.end(), shorterString());
    stable_sort(words.begin(), words.end(), 
                [](const string &s1, const string &s2)
                {
                    cout << "lambda" << endl;
                    return s1.size() > s2.size(); });
}
