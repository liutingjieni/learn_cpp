/*************************************************************************
	> File Name: copy.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年06月03日 星期三 16时02分29秒
 ************************************************************************/

#include <iostream>
using namespace std;

class base {
public:
    base(const base &b) : class_num(b.class_num), class_name(b.class_name) {  }
    base(int n1, const string &str1): class_num(n1), class_name(str1) {  }
private:
    int class_num;
    string class_name;
};

class stu : public base {
public:
    // copying函数应该确保复制"对象内的所有成员变量"及"所有base class 成员",
    stu(int n, const string &str, int n1, const string &str1): num(n), name(str), base(n1, str1){  }
    stu(const stu &s) : num(s.num), name(s.name), base(s) {  }
    stu& operator=(const stu &s)
    {
        num = s.num; 
        name = s.name;
    }
private:
    int num;
    string name;
};

int main()
{
    stu s(1, "la", 2, "er");
}

