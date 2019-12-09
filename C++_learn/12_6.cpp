/*************************************************************************
	> File Name: 12_6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 16时00分36秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<memory>
using namespace std;

void funb(vector<int> *p)
{
    for (auto i : *p) {
        cout << i << endl;
    }
}
void funa(vector<int> *p)
{
    int i;
    cin >> i;
    p->push_back(i);
}

void read_ints(shared_ptr<vector<int>> pv)
{
    int v;
    while (cin >> v) {
        pv->push_back(v);
    }
}

void print_ints(shared_ptr<vector<int>> pv)
{
    for (const auto &v :*pv) {
        cout << v << " ";
    }
    cout << endl;
}
int main()
{
    //shared_ptr<vector<int>> p = make_shared<vector<int>>();
    shared_ptr<vector<int>> p(new(vector<int>));
    
    //vector<int> *p = new vector<int>;
    //funa(p);
    //funb(p);
    read_ints(p);
    print_ints(p);
    //delete p;
    //p = nullptr;
    return 0;

    // sp成为引用技术为1，但int对象已经被释放。成为类似空悬指针的shared_ptr
    auto sp = make_shared<int>();
    auto pi= sp.get();
    delete pi;
    
}
