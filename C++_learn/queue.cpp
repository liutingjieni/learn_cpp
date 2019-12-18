/*************************************************************************
	> File Name: queue.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月18日 星期三 19时28分16秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Queue{
public:
    void queue_push(void *data);
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


void Queue::queue_push(void *data)
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

