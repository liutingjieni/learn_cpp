/*************************************************************************
	> File Name: try_catch.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月12日 星期六 17时25分29秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int a,b;
    while (cin >> a >> b) {
        try {
            cout << a / b << endl;
        } 
        catch (exception err) {
            cout << err.what()
                 << "请重新输入2" << endl; 
        }
        catch (range_error err) {
            cout << err.what()
                 << "请重新输入3" << endl; 
        }
        catch (runtime_error err) {
            cout << err.what()
                 << "请重新输入" << endl; 
        }
        catch (overflow_error err) {
            cout << err.what()
                 << "请重新输入4" << endl; 
        }
        catch (underflow_error err) {
            cout << err.what()
                 << "请重新输入5" << endl;
        }
    }
}
