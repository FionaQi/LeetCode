#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
 public:
	 TreeNode* sortedListToBST(ListNode* head) {
		 if (!head)   return nullptr;
		 return buildTree(head, nullptr);
	 }
 private:
	 // how to find middle of any given (start, end) -> set a tail ptr
	 TreeNode* buildTree(ListNode* head, ListNode* tail) {
		 if (head == tail)        return nullptr;
		 if (head->next == tail)  return new TreeNode(head->val);
		 ListNode *slow = head, *fast = head;
		 while (fast != tail && fast->next != tail) {
			 slow = slow->next;
			 fast = fast->next->next;
		 }
		 TreeNode *root = new TreeNode(slow->val);
		 root->left = buildTree(head, slow);
		 root->right = buildTree(slow->next, tail);
		 return root;
	 }
 };

 int main() {
    int i = 0;
}