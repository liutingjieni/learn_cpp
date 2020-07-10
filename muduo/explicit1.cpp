/*************************************************************************
	> File Name: explicit1.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年05月07日 星期四 14时50分46秒
 ************************************************************************/

#include <iostream>
using namespace std;

class SmallInt {
public:
    explicit operator int() const { return val; }
private:
    size_t val;
};

int main()
{
    SmallInt si = 3;
    si + 3;
}
