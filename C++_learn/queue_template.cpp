/*************************************************************************
	> File Name: queue_template.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月25日 星期三 22时05分32秒
 ************************************************************************/

#include <iostream>
#include <memory>
using namespace std;

template <typename T> class Queue {
public:
    Queue() {  }
    void queue_push(T &data);
    T &queue_pop();
    const int queue_size() const { return size;  }
private:
    class Node {
    public:
        T& data;
        Node *next;
        Node (T &data) : data(data), next(0) {  }
    };
    Node *head;
    Node *end;
    size_t size = 0;
};

template <typename T>
void Queue<T>::queue_push(T &data)
{
    Node *node = new Node(data);
    if (size != 0) {
        end->next = node;
        end = node;            
    }
    else {
        head = node;
        end = head;            
    }
    end->next = NULL;
    size++;
}

template <typename T>
T &Queue<T>::queue_pop()
{
    if (size > 0) {
        T &data = head->data;
        Node *t = head;
        head =  head->next;
        delete t;
        size--;
        return data;        
    }
}

int main()
{
    Queue<int> queue;
    int a[10];
    for (int i = 0; i < 10; ++i) {
        a[i] = i;
        queue.queue_push(a[i]);
    }

    for (int i = 0; i < 8 ; ++i) {
        cout << queue.queue_pop() << " " << ends;
            
    }

    cout << endl << queue.queue_size() << endl;

    for (int i = 0; i < 10 ; i++) {
        a[i] = i + 10;
        queue.queue_push(a[i]);    
    }

    cout << queue.queue_size() << endl;
    cout << queue.queue_pop() << endl;
    cout << queue.queue_size() << endl;

}

