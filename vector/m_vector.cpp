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

template <typename> class m_vector;

template <typename T> m_vector<T>& Swap(m_vector<T> &, m_vector<T> &);

template <typename T> 
class m_vector {
friend m_vector<T>& Swap<T> (m_vector<T> &, m_vector<T> &);
public:
    typedef T* Iterator;
    
    m_vector<T>(); 
    m_vector<T>(const m_vector<T>& t);
    m_vector<T>(int n);
    m_vector<T>(int n, const T& t);
    bool empty() {return last - first;}
    int size() {return last - first; }
    T operator[](size_t n) {return *(first + n);}
    T at(size_t n) { return *(first +n); }
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
    m_vector<T>& Swap(m_vector<T> &);
    Iterator insert(Iterator, const T &);
    Iterator insert(Iterator, int, const T &);
    Iterator insert(Iterator, Iterator, Iterator);
    Iterator erase(Iterator);
    Iterator erase(Iterator, Iterator);
    void clear() { delete []first; }

    ~m_vector<T>() { delete []first; }

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
        last++;
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

template <typename T> 
m_vector<T>& m_vector<T>::Swap(m_vector<T> &m)
{
    T*t;
    t = m.first;
    m.first = first;
    first = t;
    t = m.last;
    m.last = last;
    last = t;
    t = m.end;
    m.end = end;
    end = t; 
}

template <typename T> 
m_vector<T>& Swap(m_vector<T> &m, m_vector<T> &n)
{
    T*t;
    t = m.first;
    m.first = n.first;
    n.first = t;
    t = m.last;
    m.last = n.last;
    n.last = t;
    t = m.end;
    m.end = n.end;
    n.end = t; 
}

template <typename T> 
T* m_vector<T>::insert(T *it, const T & t)
{
    if (end - last > 0) {
        for(auto a = last; a > it; a--) {
            *a = *(a - 1);
        }
        *it = t;
    }
    else {
        int n = end - first;
        T *temp = new T[n * 2];
        int i;
        for(i = 0; first + i < it; i++) {
            *(temp + i) = *(first + i);
        }
        *(temp + i++) = t;
        for(;i < last - first + 1; i++) {
            *(temp + i) = *(first + i - 1);
        }
        last = temp + (last - first) + 1;
        end = temp + (end - first) * 2 ;
        delete []first;
        first = temp;
    }
}

template <typename T> 
T* m_vector<T>::insert(T *it, int n, const T & t)
{
    if (end - last >= n) {
        for(auto a = last + n - 1; a > it; a--) {
            *a = *(a - n);
        }
        for(int i = 0; i < n; i++) {
            *(it + i) = t;
        }
        last = last + n ;
    }
    else {
        cout << "lalal" << endl;
        int len = (end - first) * 2;
        T *temp = new T[len];
        while (len < last - first + n ) {
            len = len * 2;
            delete []temp;
            T * temp = new T[len];
        }
        int i;
        for(i = 0; first + i < it; i++) {
            *(temp + i) = *(first + i);
        }
        int tmp = n + i;
        for(; i < tmp; i++) {
            *(temp + i) = t;
        }
        for(;i < last - first + n; i++) {
            *(temp + i) = *(first + i - n);
        }
        last = temp + (last - first) + n;
        end = temp + (end - first) * 2 ;
        delete []first;
        first = temp;
    }
}
template <typename T> 
T* m_vector<T>::insert(T *it, T*n, T*m)
{
    if (end - last >= m - n) {
        for(auto a = last + (m - n) - 1; a > it; a--) {
            *a = *(a - (m - n));
            cout << *a << endl; 
        }
        int t = m - n;
        for(int i = 0; i < t; i++) {
            *(it + i) = *(n++);
        }
        last = last + t;
    }
    else {
        int len = end - first;
        len = len * 2;
        T *temp = new T[len];
        while (len < last - first + (m - n) ) {
            len = len * 2;
            delete []temp;
            T * temp = new T[len];
        }
        int i;
        for(i = 0; first + i < it; i++) {
            *(temp + i) = *(first + i);
        }
        int t = (m - n) + i;
        T* tmp = n;
        for(; i < t; i++, tmp++) {
            *(temp + i) = *tmp;
        }
        for(;i < last - first + m - n; i++) {
            *(temp + i) = *(first + i - (m - n));
        }
        last = temp + (last - first) + (m - n);
        end = temp + (end - first) * len  ;
        delete []first;
        first = temp;
    }
}

template <typename T> 
T* m_vector<T>::erase(T *it)
{
    last--;
    for(auto a = it; a < last; a++) {
        *a = *(a + 1);
    }
    return it + 1;
}

template <typename T> 
T* m_vector<T>::erase(T *n, T* m)
{
    last = last - (m - n);
    for(auto a = n; a < last; a++) {
        *a = *(a + (m - n));
    }
    return m;
}


int main()
{
    m_vector<int> t;
    m_vector<int> t2(3,10);
    m_vector<int> t1(t2);
    m_vector<int> t3(5);
    t3.push_back(11);
    t.push_back(12);
    t.push_back(12);
    m_vector<int> t4 = t;
    cout << *(t4.begin_()) <<*(t4.end_()) << endl;
    cout << (t == t4);
    cout << (t != t2);
    cout << (t > t4);
    cout << (t >= t4);
    cout << (t < t4);
    cout << (t <= t4);
    cout << t2.size() << endl;
    t2.insert(t2.begin_() + 1, 1);
    cout << t2.size() << endl;
    for(int i = 0; i < t2.size(); i++) {
        cout << "22222222222222 "<< t2[i] << endl;
    }
    t2.insert(t2.begin_() + 1,3, 2);
    for(int i = 0; i < t2.size(); i++) {
        cout << "22222222222222 "<< t2[i] << endl;
    }
    t2.insert(t2.begin_() + 1, t3.begin_(), t3.begin_()+2);
    for(int i = 0; i < t2.size(); i++) {
        cout << "3333333333333 "<< t2[i] << endl;
    }
}


#endif
