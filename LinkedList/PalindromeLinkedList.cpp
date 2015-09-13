#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head);

// or using stack
bool isPalindrome(ListNode *head) {
	ListNode *fast = head, *slow = head;
	if (!head)
		return false;
	if (!head->next)
		return true;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode *rhs = reverse(slow);
	ListNode *lhs = head;
	while (rhs) {
		if (lhs->val != rhs->val)
			return false;
		else {
			lhs = lhs->next;
			rhs = rhs->next;
		}
	}
	return true;
}
ListNode *reverse(ListNode *head){
	if (!head || !head->next)
		return head;
	ListNode *pre = nullptr;
	ListNode *cur = head;
	while (cur) {
		const ListNode *sec = cur->next;
		cur->next = pre;
		pre = cur;
		cur = const_cast<ListNode *>(sec);
	}
	return pre;
}