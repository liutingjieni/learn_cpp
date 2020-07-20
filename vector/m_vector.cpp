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
    m_vector<T>(); 
    m_vector<T>(const m_vector<T>& t);
    m_vector<T>(int n);
    m_vector<T>(int n, const T& t);
    m_vector<T>& operator = (const m_vector<T>& t);
    bool empty() {return last - first;}
    int size() {return (last - first) / sizeof(T); }
    T operator[](size_t n) {return *(first + n);}
    void push_back(const T& t);


private:
    T *first;
    T *last;
    T *end;
};

template <typename T> m_vector<T>::m_vector()
    : first(new T[10]),
      end(first + sizeof(T) *9)
{
    
}

template <typename T>
m_vector<T>::m_vector(const m_vector<T>& t)
    : first(new T[(end-first) / sizeof(T)]),
      end(first + (t.end - t.first)),
      last(first + (t.last - t.first))
{
    int num = (t.last - t.first) / sizeof(T);
    cout << num << endl;
    for (int i = 0; i < num; i++) {
        *(first + i) = *(t.first + i );
    }
}

template <typename T>
m_vector<T>& m_vector<T>::operator=(const m_vector<T>& t)
{
    cout << "AAAAA" << endl;
    //delete []first;
    //first = new T[(end-first) / sizeof(T)];
    //end = first + (t.end - t.first);
    //last = first + (t.last - t.first);

    //int num = (t.last - t.first) / sizeof(T);
    //for (int i = 0; i < num; i++) {
      //  *(first + i) = *(t.first + i);
        //cout << *(first +i) << endl;
    //}
    //return this;
}

template <typename T>
m_vector<T>::m_vector(int n, const T& t)
    : first(new T[n]),
      last(first + (n * sizeof(T))),
      end(last)
{
    for (int i = 0; i < n; i++) {
        *(first + i) = t;
    }
}

template <typename T>
m_vector<T>::m_vector(int n)
    : first(new T[n]),
      last(first + (n * sizeof(T))),
      end(last)
{
    cout << n << endl; 
}

template <typename T>
void m_vector<T>::push_back(const T& t)
{
    if (end - last > 0) {
        *(++last) = t;
    }
    else {
        T *temp = new T[(end - first)/sizeof(T) * 2];
        for(int i = 0; i < (end - first); i++) {
            *(temp + i) = *(first + i);
        }
        last = temp + (last - first);
        end = temp + (end - first) * 2;
        delete []first;
        first = temp;
        *(++last) = t;
    }
}

int main()
{
    m_vector<int> t(2, 3);
    m_vector<int> t1(t);
    m_vector<int> t3(5);
    //m_vector<int> t2=t; // wrong->
    m_vector<int> t4;
    t4 = t;
    cout << t.empty();
    cout << t.size() << endl;
    cout << t[0] << " " << t[1] << endl;
    t.push_back(5);
    cout << t.size() << endl;
    //t3.push_back(6);
    //
}

#endif
