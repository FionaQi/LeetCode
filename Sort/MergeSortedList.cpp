#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(INT_MIN);
        ListNode *cur = &dummy;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                ListNode *temp = l1->next;
                l1->next = cur->next;
                cur->next = l1;
                l1 = temp;
                cur = cur->next;
            } else {
                ListNode *temp = l2->next;
                l2->next = cur->next;
                cur->next = l2;
                l2 = temp;
                cur = cur->next;
            }
        }
        if(l1) {
            cur->next = l1;
        }
        if(l2) {
            cur->next = l2;
        }
        return dummy.next;
}

int main() {
    ListNode *node = new ListNode(1);
    node->next = new ListNode(5);
//    node->next->next = new ListNode(8);
//    node->next->next->next = new ListNode(8);
    
    ListNode *node2 = new ListNode(0);
    node2->next = new ListNode(0);
    node2->next->next = new ListNode(1);
    node2->next->next->next = new ListNode(8);
    
    ListNode *result = mergeTwoLists(node, node2);
    for(; result != NULL; result = result->next ) {
        std::cout << result->val << std::endl;
    }
    
    return 0;
}