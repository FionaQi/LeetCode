#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 void inOrder(TreeNode *root, vector<int> &output);
 // inorder, than increase array
 bool isValidBST(TreeNode* root) {
	 if (!root || (!root->left && !root->right)
		 return true;
	 vector<int> inorder;
	 inOrder(root, inorder);
	 for (auto i = 0; i < inorder.size() - 1; i++) {
		 if (inorder[i] > inorder[i + 1])
			 return false;
	 }
	 return true;
 }
 void inOrder(TreeNode *root, vector<int> &output) {
	 if (!root)	return;
	 if (root->left) {
		 inOrder(root->left, output);
	 }
	 output.push_back(root->val);
	 if (root->right) {
		 inOrder(root->right, output);
	 }
 }

 int main() {
    int i = 0;
}