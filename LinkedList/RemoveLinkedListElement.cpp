#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode* removeElements(ListNode* head, int val) {
    if( !head )
        return head;
	ListNode dummy(-1);
	dummy.next = head;
    ListNode *cur = &dummy;
    while( cur->next ){
        if( val == cur->next->val ){
            ListNode *temp = cur->next;
            cur->next = temp->next;
            delete temp;
		}
		else {
			cur = cur->next;
		}
    }
    return dummy.next;
}


int main()
{
	ListNode h(3);
	ListNode h2(2);
	ListNode h3(4);

	h.next = &h2;
	h2.next = &h3;
	h3.next = NULL;
	ListNode * res = removeElements(&h, 3);
	//int t = searchInsert(A, 2, 2);
	return 0;
}