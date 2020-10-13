/*************************************************************************
	> File Name: template_method_1.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月13日 星期二 21时45分57秒
 ************************************************************************/

class Library {
public:
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
};

class Applicaton {
public: 
    bool step2() 
    {
        //...
    }
    void step4()
    {
        //....
    }
};


int main()
{
    Library lib;
    Applicaton app;
    
    lib.step1();
    if (app.step2()) {
        lib.step3();
    }

    for (int i = 0; i < 4; i++) {
        app.step4();
    }
    lib.step5();

}

