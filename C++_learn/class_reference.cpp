/*************************************************************************
	> File Name: class_reference.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年05月28日 星期四 23时31分18秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

template<class T>
class NamedObject {
public:
    NamedObject(string &name, const T& value):
    NameValue(name), objectValue(value) {  }
private:
    string &NameValue;
    const T objectValue;
};

int main()
{
    string newDog("per");
    string oldDog("Sat");

    NamedObject<int> p(newDog, 2);
    NamedObject<int> q(oldDog, 36);

    //p = q;
    //reference不能改指向不同对象
    //如果你打算在一个内含reference成员的class内支持赋值操作.你必须自己定义copy assignment 操作
}
