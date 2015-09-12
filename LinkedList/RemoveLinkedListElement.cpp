#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

    ListNode* removeElements(ListNode* head, int val) {
        if( head == NULL )
            return head;
        while( head != NULL && head->val == val ){
            ListNode *temp = head;
            head = head->next;
			temp = NULL;
			delete temp;
        }
        if( head == NULL )
            return NULL;
        ListNode *cur = head;
        while( cur->next != NULL && cur != NULL ){
            if( val == cur->next->val ){
                ListNode *temp = cur->next;
                cur->next = temp->next;
                delete temp;
            }
            cur = cur->next;
        }
        return head;
    }


int main()
{
	ListNode h(3);
	ListNode h2(2);
	ListNode h3(4);

//	h.next = &h2;
//	h2.next = &h3;
//	h3.next = NULL;
	ListNode * res = removeElements(&h, 3);
	//int t = searchInsert(A, 2, 2);
	return 0;
}