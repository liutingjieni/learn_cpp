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
}

int main()
{
    Library *lib;
    
    step1();
    if (step2()) {
        step3();
    }

    for (int i = 0; i < 4; i++) {
        step4();
    }
    step5();

}

