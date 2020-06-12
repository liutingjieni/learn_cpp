/*************************************************************************
	> File Name: 1.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年06月12日 星期五 11时32分17秒
 ************************************************************************/

#include <iostream>
using namespace std;

class base {
public:
    virtual void camera();
    virtual void ImageQualitySet();
private:
    virtual void Coding();
};

class derived : public base {
private:
    void ImageQualitySet();
public:
    void menu();
    void camera();
};

class base2 {
public:
    virtual void camera();
    virtual void ImageQualitySet();
private:
    virtual void Coding();
};

class derived2 : public base2 {
private:
    void ImageQualitySet();
    void camera();
public:
    void menu();
};

class base3 {
public:
    virtual void camera();
    virtual void ImageQualitySet();
private:
    virtual void Coding();
};

class derived3 : public base3 {
protected:
    void ImageQualitySet();
    void camera();
private:
    void menu();
};
