/*************************************************************************
	> File Name: literal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月08日 星期日 14时43分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    // \后紧跟1~3个八进制数字，其中数字部分表示的是字符对应的数值
    
    cout << "Who goes with F\145rgus?\012";
    
    //输出为：Who goes with Fergusi?
    
    // \x后紧跟1个或多个十六进制数字
    
    cout << "Hi \x4dO\115!\n";
    
    // 输出为：Hi MOM!
   
    //0x或0X开头的代表十六进制，以0开头的代表八进制
    int month = 9, day = 7;
    cout << month << endl << day << endl;

    //int month1 = 09; // 报错
    int day1 = 07;
    cout << day1 << endl;

    cout << 3.14e1L * 10 << endl;
    cout << 1024.0F << endl;
    cout << 3.14L << endl;

}
