/*************************************************************************
	> File Name: queue.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月18日 星期三 19时28分16秒
 ************************************************************************/

#include <iostream>
#include <memory>

using namespace std;



class Queue{
public:
    void queue_push(auto data);
    void *queue_pop();
    int queue_size() {return size;}

private:
    typedef struct node {
        void *data;
        struct node *next;
    }Node;
    Node *head;
    Node *end;
    size_t size = 0;
};

void Queue::queue_push(auto data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data =  data;
    if (size!= 0) {
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
        free(head);
        head =  head->next;
        size--;
        return data;    
    }

}

//自定义指针,容易造成内存泄露,产生非法引用
/*int main()
{
    Queue *queue = new Queue;
    int a[10], b[10];
    for (int i = 0; i < 10 ; i++) {
        a[i] = i;
        queue->queue_push(&a[i]);
    }
    for (int i = 0; i < 8 ; i++) {
        b[i] = *(int *)queue->queue_pop();
        cout << b[i] << ' ' << ends;
    }
    cout << queue->queue_size() << endl;
    for (int i = 0; i < 10 ; i++) {
        a[i] = i + 10;
        queue->queue_push(&a[i]);
    }
    cout << queue->queue_size() << endl;
    cout << *(int *)queue->queue_pop() << endl;
    cout << queue->queue_size() << endl;

    free(queue);
}*/

// 智能指针
int main()
{
    auto queue = make_shared<Queue> ();
    int a[10], b[10];
    for (int i = 0; i < 10 ; i++) {
        a[i] = i;
        queue->queue_push(&a[i]);
    }
    for (int i = 0; i < 8 ; i++) {
        b[i] = *(int *)queue->queue_pop();
        cout << b[i] << ' ' << ends;
    }
    cout << queue->queue_size() << endl;
    for (int i = 0; i < 10 ; i++) {
        a[i] = i + 10;
        queue->queue_push(&a[i]);
    }
    cout << queue->queue_size() << endl;
    cout << *(int *)queue->queue_pop() << endl;
    cout << queue->queue_size() << endl;
}


