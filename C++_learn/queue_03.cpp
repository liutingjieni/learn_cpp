/*************************************************************************
	> File Name: queue_02.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月18日 星期三 20时29分43秒
 ************************************************************************/

#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class Queue {
public:
    void queue_push(void *data);
    void *queue_pop();
    const int queue_size() const { return size; }
private:
    typedef struct node {
        void *data;
        shared_ptr<struct node> next;
    }Node;
    shared_ptr<Node> head = make_shared<Node> ();
    shared_ptr<Node> end = make_shared<Node> ();
    size_t size = 0;
};

//const auto &data 对地址的引用
void Queue::queue_push(void* data)
{
    auto node = make_shared<Node> ();
    node->data =  data;
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

void *Queue::queue_pop()
{
    if (size > 0) {
        void *data = head->data;
        head =  head->next;
        size--;
        return data;        
    }
}

int main()
{
    auto queue = make_shared<Queue> ();
    vector<int> a;
    for (int i = 0; i < 10; ++i) {
        a.push_back(i);
    }

    for (int it : a) {
        queue->queue_push(&it);  
    }


    for (int i = 0; i < 8 ; ++i) {
        cout << *(int *)queue->queue_pop() << " " << ends;
    }

    cout << endl << queue->queue_size() << endl;

    for (int i = 0; i < 10 ; i++) {
        a[i] = i + 10;
        queue->queue_push(&a[i]);    
    }

    cout << queue->queue_size() << endl;
    cout << *(int *)queue->queue_pop() << endl;
    cout << queue->queue_size() << endl;
}



