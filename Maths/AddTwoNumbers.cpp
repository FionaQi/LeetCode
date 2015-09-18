#include<iostream>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int carry = 0;
	ListNode sum = ListNode(INT_MIN);
	ListNode *cur = &sum;
	while (l1 && l2) {
		cur->next = new ListNode((l1->val + l2->val + carry) % 10);
		carry = (l1->val + l2->val + carry) / 10;
		cur = cur->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1 != NULL) {
		cur->next = new ListNode((l1->val + carry) % 10);
		carry = (l1->val + carry) / 10;
		cur = cur->next;
		l1 = l1->next;
	}
	while (l2 != NULL) {
		cur->next = new ListNode((l2->val + carry) % 10);
		carry = (l2->val + carry) / 10;
		cur = cur->next;
		l2 = l2->next;
	}
	while (carry != 0) {
		cur->next = new ListNode(carry);
		carry = 0; //!!!!!!!!Notice
	}
	return sum.next;
}

void main()
{

}