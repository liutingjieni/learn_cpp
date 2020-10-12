/*************************************************************************
	> File Name: listsum.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年07月17日 星期五 17时40分48秒
 ************************************************************************/

#include <iostream>
using namespace std;
struct ListNode {
       int val;
             ListNode *next;
             ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
                struct ListNode *l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
        while (l1->next || l2->next) {
                        l3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            if(l1->val + l2->val >= 10) {
                                l3->next->val = 1;
                                l3->val = (l1->val + l2->val) % 10;
                            
            }
            else {
                                l3->val = l1->val + l2->val;
                            
            }
                        l1 = l1->next;
                        l2 = l2->next;
                    
        }
                return l3;
            
    }

};
