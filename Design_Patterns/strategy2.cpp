/*************************************************************************
	> File Name: strategy2.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月14日 星期三 16时09分04秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Context;
class TaxStrategy {
public:
    virtual double Calculate(const Context& context) = 0;
    virtual ~TaxStrategy() {  }
};

class CNTax : public TaxStrategy {
public:
    virtual double Calculate(const Context& context) 
    {
        //CN************
    }
};
class USTax : public TaxStrategy {
public:
    virtual double Calculate(const Context& context) 
    {
        //US************
    }
};
class DETax : public TaxStrategy {
public:
    virtual double Calculate(const Context& context) 
    {
        //DE************
    }
};

//改变, 
class FRTax : public TaxStrategy {
public:
    virtual double Calculate(const Context& context) 
    {
        //FR************
    }
};

class SalesOrder {
private:
    TaxStrategy* strategy; //支持多态性, 所以用指针, 不能用对象

public:
    SalesOrder(StrategyFactory* strategyFactory) 
    {
        this->strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder()
    {
        delete this->strategy;
    }
    double CalculateTax()
    {
        //...
        Context context;

        double val = strategy->Calculate(context); //多态调用
    }
};
