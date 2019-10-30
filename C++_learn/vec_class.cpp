/*************************************************************************
	> File Name: vec_class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月25日 星期五 21时36分29秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Stu{
private:
    string name;
    int num;
public:
    Stu() = default;
    Stu(string n, int num):name(n), num(num) {}
};

int main()
{
    vector<Stu> vec(10);
}
