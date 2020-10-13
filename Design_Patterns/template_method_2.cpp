/*************************************************************************
	> File Name: template_method_1.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月13日 星期二 21时45分57秒
 ************************************************************************/

class Library {
public:
    
    void run() 
    {
        step1();
        if (step2()) { //支持变化 ==> 虚函数的多态
            step3();
        }

        for (int i = 0; i < 4; i++) {
            step4();  //支持变化 ==> 虚函数的多态 
        }
        step5();
    }

protected:
    void step1()
    {
        //....
    }
    void step3()
    {
        //...
    }

    void step5()
    {
        //...
    }
    virtual ~Library() {  }
    virtual bool step2() = 0;
    virtual void step4() = 0;

};

int main()
{
    Library *lib;
    

}

