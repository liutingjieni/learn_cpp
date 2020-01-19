#include <iostream>
using namespace std;

typedef char* Iterator;

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
friend String &swap(String &, String &);

public:
    String();
    String(const char *t);
    String(const String& t);
    String(size_t st, char ch);
    String &operator=(const char *);
    String &operator=(const String &);
    char operator[](size_t n) { return s[n]; }
    size_t size() { return len; };
    Iterator begin();
    Iterator end();
    const Iterator cbegin();
    const Iterator cend();
    String &swap(String &);
    void push_back(char);
    void push_front(char);
    void push_back(int);
    void push_front(int);
    void pop_back();
    void pop_front();
    Iterator insert(Iterator, char);
    Iterator insert(Iterator, int, char);
    Iterator insert(Iterator, Iterator, Iterator);
    bool empty() { return len > 0 ? 0 : 1;}

    ~String() { delete [] s; }
private:
    char *s;
    size_t len = 0;
};

String::String()
{
    s = new char;
}

String::String(const char *t)
{
    const char *p = t; 
    while(*p++) {
        len++;
    }
    s = new char[len + 1];  
    for (int i = 0; i < len ;i++) {
        s[i] = t[i];
    }
    s[len] = '\0';
}

String::String(const String& t)
{
    len = t.len;
    s = new char[len + 1];
    for (int i = 0; i < len; i++) {
        s[i] = t.s[i];
    }
    s[len] = '\0';
}

Iterator String::begin()
{
    return s;
}

Iterator String::end()
{
    return (s + len);
}

const Iterator String::cbegin()
{
    return s;
}

const Iterator String::cend()
{
    return (s + len);
}

String &String::swap(String &s2)
{
    char*p = s2.s;
    int t = s2.len;
    s2.s = s;
    s2.len = len;
    s = p;
    len = t;
}

String &swap(String &s1, String &s2)
{
    char*p = s2.s;
    int t = s2.len;
    s2.s = s1.s;
    s2.len = s1.len;
    s1.s = p;
    s1.len = t;
    
}

void String::push_back(char ch)
{
    char *t = new char[len + 1];
    for (int i = 0; i < len; i++) {
        t[i] = s[i]; 
    }
    t[len] = ch;
    len = len + 1;
    delete []s;
    s = t;
}

void String::push_front(char ch)
{
    char *t = new char[len + 1];
    t[0] = ch;
    for (int i = 0; i < len; i++) {
        t[i + 1] = s[i]; 
    }
    len = len + 1;
    delete []s;
    s = t;
}

void String::push_back(int ch)
{
    char *t = new char[len + 1];
    for (int i = 0; i < len; i++) {
        t[i] = s[i]; 
    }
    t[len] = ch;
    len = len + 1;
    delete []s;
    s = t;
}

void String::push_front(int ch)
{
    char *t = new char[len + 1];
    t[0] = ch;
    for (int i = 0; i < len; i++) {
        t[i + 1] = s[i]; 
    }
    len = len + 1;
    delete []s;
    s = t;
}

Iterator String::insert(Iterator it, char ch)
{
    char *t = new char[len + 1];
    int i;
    for (i = 0; begin() + i != it; i++) {
        t[i] = s[i];
    }
    t[i] = ch;
    for(int j = i; j < len + 1; j++) {
        t[j + 1] = s[j];
    }
    len = len + 1;
    delete []s;
    s = t;
    return &t[i];
}

Iterator String::insert(Iterator it, int n, char ch)
{
    char *t = new char[len + n];
    int i;
    for (i = 0; begin() + i != it; i++) {
        t[i] = s[i];
    }
    for(int j = i + n ; j < len + n; j++) {
        t[j] = s[j-n];
    }
    len = len + n;
    while (n--) t[i + n] = ch;
    delete []s;
    s = t;
    return &t[i];
}

Iterator String::insert(Iterator it, Iterator it1, Iterator it2)
{
    int n = 0;
    for (auto t = it1; t != it2; t++) n++;
    char *t = new char[len + n + 1];
    int i, j;
    for (i = 0; begin() + i != it; i++) {
        t[i] = s[i];
    }
    for (j = i; j < i + n; j++) {
        t[j] = *it1;
        it1++;
    }
    for( ; j < len + n; j++) {
        t[j] = s[j - n];
    }
    t[len + n] = '\0';
    len = len + n;
    delete []s;
    s = t;
    return &it[i];
    
}
void String::pop_back()
{
    len = len - 1;
    s[len] = '\0';
}
void String::pop_front()
{
    for(int i = 1; i < len; i++) {
        s[i - 1] =s[i];
    }
    len = len -1;
    s[len - 1] = '\0';
}

String &String::operator=(const char *t)
{
    delete []s;
    const char *p = t;
    len = 0;
    while(*p++) {
        len++;
    }
    s =new char[len + 1];
    for (int i = 0; i < len; i++) {
        s[i] = t[i];
    }
    s[len] = '\0';
}

String &String::operator=(const String &t) 
{
    delete []s;
    len = t.len;
    s = new char[len + 1];
    for (int i = 0; i < len; i++) {
        s[i] =t.s[i];
    }
    s[len] = '\0';
}

String::String(size_t st, char ch) {
    len = st;
    s = new char[len + 1];
    for (int i = 0; i < len; i++) {
        s[i] = ch;
    }
    s[len] = '\0';
}

ostream &operator<<(ostream &os, const String &s)
{
    os << s.s;
    return os; 
}


istream &operator>>(istream &is, String &s)
{
    delete []s.s;
    s.s = new char[100];
    is >> s.s;
    s.len = 0;
    char *p = s.s;
    while(*p++)
        s.len++;
    return is;
}

String operator+(const String &s1, const String &s2)
{
    int len = s1.len + s2.len;
    String s = new char[len];
    s.len = len;
    for (int i = 0; i < s1.len; i++) {
        s.s[i] = s1.s[i];
    }
    for (int i = 0; i < s2.len; i++) {
        s.s[i + s1.len] = s2.s[i];
    }
    return s;
}

String operator+(const char *s1, String &s2)
{
    int len = 0;
    const char *t = s1;
    while (*t++) len++;
    String s = new char[len + s2.len];
    s.len = len + s2.len;
    for (int i = 0; i < len; i++) {
        s.s[i] = s1[i];
    }
    for (int i = 0; i < s2.len; i++) {
        s.s[i + len] = s2.s[i];
    }
    return s;
}

String operator+(String &s1, const char *s2)
{
    int len = 0;
    const char *t = s2;
    while (*t++) len++;
    String s = new char[len + s1.len];
    s.len  = len + s1.len;
    for (int i = 0; i < s1.len; i++) {
        s.s[i] = s1.s[i];
    }
    for (int i = 0; i < len; i++) {
        s.s[i + s1.len] = s2[i];
    }
    return s;
}

bool operator==(const String &s1, const String &s2)
{
    int flag = 0;
    if (s1.len == s1.len) {
        for(int i = 0; i < s1.len; i++) {
            if (s1.s[i] == s2.s[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == s1.len) {
            return 1;
        }
    }
    return 0;
}
bool operator==(String &s1, const char *s2)
{
    int len = 0;
    const char *t = s2;
    while (*t++) len++;
    
    int flag = 0;
    if (s1.len == len) {
        for(int i = 0; i < s1.len; i++) {
            if (s1.s[i] == s2[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == s1.len) {
            return 1;
        }
    }
    return 0;
}
bool operator==(const char *s1 ,String &s2)
{
    int len = 0;
    const char *t = s1;
    while (*t++) len++;
    
    int flag = 0;
    if (len == s2.len) {
        for(int i = 0; i < len; i++) {
            if (s1[i] == s2.s[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == len) {
            return 1;
        }
    }
    return 0;
}
bool operator!=(const String &s1, const String &s2)
{
    int flag = 0;
    if (s1.len == s2.len) {
        for(int i = 0; i < s1.len; i++) {
            if (s1.s[i] == s2.s[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == s1.len) {
            return 0;
        }
    }
    return 1;
}
bool operator!=(String &s1, const char *s2)
{
    int len = 0;
    const char *t = s2;
    while (*t++) len++;
    
    int flag = 0;
    if (s1.len == len) {
        for(int i = 0; i < s1.len; i++) {
            if (s1.s[i] == s2[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == s1.len) {
            return 0;
        }
    }
    return 1;
    
}
bool operator!=(const char *s1, String &s2)
{
    int len = 0;
    const char *t = s1;
    while (*t++) len++;
    
    int flag = 0;
    if (len == s2.len) {
        for(int i = 0; i < len; i++) {
            if (s1[i] == s2.s[i]) {
                flag++;
            }
            else {
                break;
            }
        }
        if (flag == len) {
            return 0;
        }
    }
    return 1;
    
}

bool operator<(const String &s1, const String &s2)
{
    int flag = 0;
    int len = s1.len < s2.len ? s1.len : s2.len;
    for(int i = 0; i < len; i++) {
        if (s1.s[i] == s2.s[i]) {
            flag++;
        }
        else if(s1.s[i] < s2.s[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return s1.len >= s2.len ? 0 : 1;
    }
}

bool operator<(String &s1, const char *s2)
{
    int len_t = 0;
    const char *t = s2;
    while (*t++) len_t++;
    
    int flag = 0;
    int len = s1.len < len_t ? s1.len : len_t;
    for(int i = 0; i < len; i++) {
        if (s1.s[i] == s2[i]) {
            flag++;
        }
        else if(s1.s[i] < s2[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return s1.len >= len_t ? 0 : 1;
    }
}
bool operator<(const char *s1, String &s2)
{
    int len_t = 0;
    const char *t = s1;
    while (*t++) len_t++;
    
    int flag = 0;
    int len = len_t < s2.len ? len_t : s2.len;
    for(int i = 0; i < len; i++) {
        if (s1[i] == s2.s[i]) {
            flag++;
        }
        else if(s1[i] < s2.s[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return len_t >= s2.len ? 0 : 1;
    }
} 

bool operator<=(const String &s1, const String &s2)
{
    int flag = 0;
    int len = s1.len < s2.len ? s1.len : s2.len;
    for(int i = 0; i < len; i++) {
        if (s1.s[i] == s2.s[i]) {
            flag++;
        }
        else if(s1.s[i] < s2.s[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return s1.len <= s2.len ? 1 : 0;
    }
}

bool operator<=(String &s1, const char *s2)
{
    int len_t = 0;
    const char *t = s2;
    while (*t++) len_t++;
    
    int flag = 0;
    int len = s1.len < len_t ? s1.len : len_t;
    for(int i = 0; i < len; i++) {
        if (s1.s[i] == s2[i]) {
            flag++;
        }
        else if(s1.s[i] < s2[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return s1.len <= len_t ? 1 : 0;
    }
}
bool operator<=(const char *s1, String &s2)
{
    int len_t = 0;
    const char *t = s1;
    while (*t++) len_t++;
    
    int flag = 0;
    int len = len_t < s2.len ? len_t : s2.len;
    for(int i = 0; i < len; i++) {
        if (s1[i] == s2.s[i]) {
            flag++;
        }
        else if(s1[i] < s2.s[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return len_t <= s2.len ? 1 : 0;
    }
} 

bool operator>(const String &s1, const String &s2)
{
    int flag = 0;
    int len = s1.len < s2.len ? s1.len : s2.len;
    for(int i = 0; i < len; i++) {
        if (s1.s[i] == s2.s[i]) {
            flag++;
        }
        else if(s1.s[i] > s2.s[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return s1.len <= s2.len ? 0 : 1;
    }
}

bool operator>(String &s1, const char *s2)
{
    int len_t = 0;
    const char *t = s2;
    while (*t++) len_t++;
    
    int flag = 0;
    int len = s1.len < len_t ? s1.len : len_t;
    for(int i = 0; i < len; i++) {
        if (s1.s[i] == s2[i]) {
            flag++;
        }
        else if(s1.s[i] > s2[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return s1.len <= len_t ? 0 : 1;
    }
}
bool operator>(const char *s1, String &s2)
{
    int len_t = 0;
    const char *t = s1;
    while (*t++) len_t++;
    
    int flag = 0;
    int len = len_t < s2.len ? len_t : s2.len;
    for(int i = 0; i < len; i++) {
        if (s1[i] == s2.s[i]) {
            flag++;
        }
        else if(s1[i] > s2.s[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return len_t <= s2.len ? 0 : 1;
    }
} 

bool operator>=(const String &s1, const String &s2)
{
    int flag = 0;
    int len = s1.len < s2.len ? s1.len : s2.len;
    for(int i = 0; i < len; i++) {
        if (s1.s[i] == s2.s[i]) {
            flag++;
        }
        else if(s1.s[i] > s2.s[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return s1.len >= s2.len ? 1 : 0;
    }
}

bool operator>=(String &s1, const char *s2)
{
    int len_t = 0;
    const char *t = s2;
    while (*t++) len_t++;
    
    int flag = 0;
    int len = s1.len < len_t ? s1.len : len_t;
    for(int i = 0; i < len; i++) {
        if (s1.s[i] == s2[i]) {
            flag++;
        }
        else if(s1.s[i] > s2[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return s1.len >= len_t ? 1 : 0;
    }
}
bool operator>=(const char *s1, String &s2)
{
    int len_t = 0;
    const char *t = s1;
    while (*t++) len_t++;
    
    int flag = 0;
    int len = len_t < s2.len ? len_t : s2.len;
    for(int i = 0; i < len; i++) {
        if (s1[i] == s2.s[i]) {
            flag++;
        }
        else if(s1[i] > s2.s[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return len_t >= s2.len ? 1 : 0;
    }
} 

int main()
{
    String s("abc");
    cout << s.size() << endl;
    cout << s  << s.size() << endl;

    String s1(s);
    cout << s1 << s1.size() << endl;
    
    String s2(10,'a');
    cout << s2 << s2.size() << endl;
    
    
    s2 = s1;
    cout << s2 << s2.size() << endl;
    const char *t = "123";
    s2 = t;
    cout << s2 << s2.size() << endl;
    
    String s3(t);
    cout << s3 << s3.size() << endl;
    
    String s4, s5;
  //  cin >> s4 >>s5;
   // cout << s4 << s4.size() << endl;
  //  cout << s5 << s5.size() << endl;

    cout << s[1] << s[2] << endl;

    cout << s4.size() << s5.size() << endl;
    String s6;
    s6 = (s4 + s5);
    cout << s6 << endl;
    
    s6 = s6 + "world";
    cout << s6 << s6.size() << endl;
    s6 = "world" + s6;
    cout << s6 << s6.size() << endl;
    s6 = s6 + "world" + s5;
    cout << s6 << s6.size() << endl;

    String s7 = "456";
    s2 = "456";
    s3 = "12";
    s4 = "454";
    cout << (s7 == s2) << endl;
    cout << (s7 == s3) << endl;
    cout << (s7 == s4) << endl;

    const char *t1 = "qwe";
    s1 = "qwe";
    cout << (s1 == t1) << endl;
    cout << (t1 == s1) << endl;
    s1 = "abc";
    cout << (s1 == t1) << endl;
    cout << (t1 == s1) << endl;
    cout << (s1 > t1) << endl;
    cout << (s1 < t1) << endl;
    cout << (s1 >= t1) << endl;
    cout << (s1 <= t1) << endl;
    
    cout << s1 << s2 << endl;
    s1.swap(s2);
    cout << s1 << s2 << endl;
    swap(s1, s2);
    cout << s1 << s2 << endl;
    
    s1.push_back('A');
    cout << s1 << s1.size() << endl;
    s1.push_front('A');
    cout << s1 << s1.size() << endl;

    s1.push_back(36);
    cout << s1 << s1.size() << endl;
    s1.push_front(36);
    cout << s1 << s1.size() << endl;

    Iterator tp = s1.insert(s1.begin() + 1, 'W');
    cout <<s1 << s1.size() <<endl;
    auto tp1 = s1.insert(s1.begin(), 3, 'B');
    cout <<s1 << s1.size() << endl;
    cout << s2 << s2.size() << endl;
    
    auto tp2 = s1.insert(s1.begin()+2, s2.begin(), s2.end());
    cout << s1 << " "<< s1.size() << endl;
    
    s1.pop_back();
    cout << s1 << " "<< s1.size() << endl;
    s1.pop_front();
    cout << s1 << s1.size() << endl;
}
