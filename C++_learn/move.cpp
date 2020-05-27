/*************************************************************************
	> File Name: move.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年02月09日 星期日 23时27分15秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;
    int operator[](int i) { return data[i]; }
    void push(int t) { data.push_back(t); }
private:
    vector<int> data;
};

Foo Foo::sorted() && 
{
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return ret;
}
int main()
{
    Foo t;
    for (int i = 0; i < 10; i++) {
        t.push(i);
    }
    for (int i = 0; i < 10; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
    v
}
