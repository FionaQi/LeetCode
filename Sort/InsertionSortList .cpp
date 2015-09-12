#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode* findInsertPos(ListNode *head, int x) {
ListNode *pre = nullptr;
for (ListNode *cur = head; cur != nullptr && cur->val <= x;
pre = cur, cur = cur->next)
;
return pre;
}

ListNode *insertionSortList(ListNode *head) {
ListNode dummy(INT_MIN);
//dummy.next = head;
for (ListNode *cur = head; cur != nullptr;) {
auto pos = findInsertPos(&dummy, cur->val);
ListNode *tmp = cur->next;
cur->next = pos->next;
pos->next = cur;
cur = tmp;
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
	ListNode * res = insertionSortList(&h);
	//int t = searchInsert(A, 2, 2);
	return 0;
}