/*************************************************************************
	> File Name: String.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年01月16日 星期四 11时41分08秒
 ************************************************************************/
#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;


class String {
friend ostream &operator<<(ostream &, const String &); 
friend istream &operator>>(istream &, String &); 
friend String operator+(const String &, const String &);
friend String operator+(String &, const char *);
friend String operator+(const char *, String &);
friend bool operator==(const String &, const String &);
friend bool operator==(String &, const char *);
friend bool operator==(const char *, String &);
friend bool operator!=(const String &, const String &);
friend bool operator!=(String &, const char *);
friend bool operator!=(const char *, String &);
friend bool operator<(const String &, const String &);
friend bool operator<(String &, const char *);
friend bool operator<(const char *, String &);
friend bool operator<=(const String &, const String &);
friend bool operator<=(String &, const char *);
friend bool operator<=(const char *, String &);
friend bool operator>(const String &, const String &);
friend bool operator>(String &, const char *);
friend bool operator>(const char *, String &);
friend bool operator>=(const String &, const String &);
friend bool operator>=(String &, const char *);
friend bool operator>=(const char *, String &);
public:
    String();
    String(const char *t);
    String(const String& t);
    String(size_t st, char ch);
    String &operator=(const char *);
    String &operator=(const String &);
    char operator[](size_t n) { return s[n]; }
    size_t size() { return len; };
    bool empty() { return len > 0 ? 0 : 1;}

    ~String() { delete [] s; }
private:
    char *s;
    size_t len = 0;
};

#endif

