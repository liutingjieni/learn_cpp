/*************************************************************************
	> File Name: StrBlob.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月06日 星期五 20时21分15秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<memory>
using namespace std;

class StrBlob{
public:
    typedef vector<string>::size_type size_type;
    StrBlob():data(make_shared<vector<string>>()) {  }
    StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {  }
    size_type size() const{ return data->size(); }
    bool empty() const {return data->empty();}

    void push_back(const string &t) {data->push_back(t);}
    void pop_back();

    string &front();
    string &back();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
    }

    cout << b1.front() << b1.back() << ends;
    return 0;
}
