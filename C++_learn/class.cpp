/*************************************************************************
	> File Name: class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月19日 星期六 17时59分49秒
 ************************************************************************/

#include "class.h"

int main()
{
    Screen myScreen(5, 2, 'X');
    myScreen.move(1,1).set('#').display();
    cout << "\n";
    myScreen.display();
    cout << "\n";
}
