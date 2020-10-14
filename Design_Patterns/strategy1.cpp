/*************************************************************************
	> File Name: strategy1.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月14日 星期三 16时05分12秒
 ************************************************************************/

#include <iostream>
using namespace std;
enum TaxBase {
    CN_TAX,
    US_TAX,
    DE_TAX,
    FR_TAX
};

class SalesOrder {
    TaxBase tax;
public:
    double CalculateTax() 
    {
        if (tax == CN_TAX) {
            //CN***********
        } 
        else if (tax == US_TAX) {
            //US***********
        }
        else if (tax == DE_TAX) {
            //DE***********
        }
        else if (tax == FR_TAX) { //更改
            //...
        }
        //...
    }
};
