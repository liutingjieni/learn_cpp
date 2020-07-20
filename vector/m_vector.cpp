/*************************************************************************
	> File Name: m_vector.h
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月20日 星期一 14时24分52秒
 ************************************************************************/

#ifndef _M_VECTOR_H
#define _M_VECTOR_H
#include <iostream>
using namespace std;



template <typename T> 
class m_vector {
public:
    typedef T* Iterator;
    
    m_vector<T>(); 
    m_vector<T>(const m_vector<T>& t);
    m_vector<T>(int n);
    m_vector<T>(int n, const T& t);
    bool empty() {return last - first;}
    int size() {return last - first; }
    T operator[](size_t n) {return *(first + n);}
    void push_back(const T& t);
    m_vector<T>& operator = (const m_vector<T>& t);
    Iterator begin_() {return first;}
    Iterator end_() { return last; }
    bool operator == (const m_vector<T>& t);
    bool operator != (const m_vector<T>& t);
    int operator < (const m_vector<T>& t);
    bool operator <= (const m_vector<T>& t);
    int operator > (const m_vector<T>& t);
    bool operator >= (const m_vector<T>& t);


private:
    T *first;
    T *last;
    T *end;
};

template <typename T> m_vector<T>::m_vector()
    : first(new T[10]),
      last(first),
      end(first + 10)
{
}

template <typename T>
m_vector<T>::m_vector(const m_vector<T>& t)
    : first(new T[(t.end-t.first)]),
      end(first + (t.end - t.first)),
      last(first + (t.last - t.first))
{

    int num = (t.last - t.first);
    for (int i = 0; i < num; i++) {
        *(first + i) = *(t.first + i );
    }
}

template <typename T>
m_vector<T>& m_vector<T>::operator=(const m_vector<T>& t)
{
    delete []first;
    first = new T[(end-first)];
    end = first + (t.end - t.first);
    last = first + (t.last - t.first);

    int num = (t.last - t.first);
    for (int i = 0; i < num; i++) {
        *(first + i) = *(t.first + i);
        cout << *(first +i) << endl;
    }
}

template <typename T>
m_vector<T>::m_vector(int n, const T& t)
    : first(new T[n]),
      last(first + n),
      end(last)
{
    for (int i = 0; i < n; i++) {
        *(first + i) = t;
    }

}

template <typename T>
m_vector<T>::m_vector(int n)
    : first(new T[n]),
      last(first + n),
      end(last)
{
}

template <typename T>
void m_vector<T>::push_back(const T& t)
{
    if (end - last > 0) {
        if(last == first) {
            *last = t;
            last++;
        }
        else {
            *last = t;
            last++;
        }
    }
    else {
        int n = end - first;
        T *temp = new T[n * 2];
        for(int i = 0; i < n; i++) {
            *(temp + i) = *(first + i);
        }
        last = temp + (last - first);
        end = temp + (end - first) * 2 ;
        delete []first;
        first = temp;
        *last = t;
    }
}
template <typename T>
bool m_vector<T>::operator==(const m_vector<T>& t)
{
    if (last - first != t.last - t.first) {
        return 0;
    }
    for(int i = 0; i < last - first; i++) {
        if (*(first + i) != *(t.first + i)) {
            return 0;
        }
    }
    return 1;
}

template <typename T>
bool m_vector<T>::operator!=(const m_vector<T>& t)
{
    if (last - first != t.last - t.first) {
        return 1;
    }
    for(int i = 0; i < last - first; i++) {
        if (*(first + i) != *(t.first + i)) {
            return 1;
        }
    }
    return 0;
}

template <typename T>
int m_vector<T>::operator>(const m_vector<T>& t)
{
    int flag = 0;
    int n1 = last - first;
    int n2 = t.last - t.first;
    int len = n1 < n2 ? n1 : n2; 
    for(int i = 0; i < len; i++) {
        if (*(first + i) == *(t.first + i)) {
            flag++;
        }
        else if (*(first + i) > *(t.first + i)) {
            return 1;
        }
        else {
            return -1;
        }
    }
    if (flag == len) {
        return 0;
    }
}
template <typename T>
int m_vector<T>::operator<(const m_vector<T>& t)
{
    int flag = 0;
    int n1 = last - first;
    int n2 = t.last - t.first;
    int len = n1 < n2 ? n1 : n2; 
    for(int i = 0; i < len; i++) {
        if (*(first + i) == *(t.first + i)) {
            flag++;
        }
        else if (*(first + i) < *(t.first + i)) {
            return 1;
        }
        else {
            return -1;
        }
    }
    if (flag == len) {
        return 0;
    }
}
template <typename T>
bool m_vector<T>::operator>=(const m_vector<T>& t)
{
    int flag = 0;
    int n1 = last - first;
    int n2 = t.last - t.first;
    int len = n1 < n2 ? n1 : n2; 
    for(int i = 0; i < len; i++) {
        if (*(first + i) == *(t.first + i)) {
            flag++;
        }
        else if (*(first + i) < *(t.first + i)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return 1;
    }
}
template <typename T>
bool m_vector<T>::operator<=(const m_vector<T>& t)
{
    int flag = 0;
    int n1 = last - first;
    int n2 = t.last - t.first;
    int len = n1 < n2 ? n1 : n2; 
    for(int i = 0; i < len; i++) {
        if (*(first + i) == *(t.first + i)) {
            flag++;
        }
        else if (*(first + i) < *(t.first + i)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (flag == len) {
        return 1;
    }
}

int main()
{
    m_vector<int> t;
    m_vector<int> t2(3,10);
    m_vector<int> t1(t2);
    m_vector<int> t3(5);
    t3.push_back(11);
    t.push_back(12);
    m_vector<int> t4 = t;
    cout << *(t4.begin_()) <<*(t4.end_()) << endl;
    cout << (t == t4);
    cout << (t != t2);
    cout << (t > t4);
    cout << (t >= t4);
    cout << (t < t4);
    cout << (t <= t4);
}

#endif
