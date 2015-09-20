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
	 bool isBalanced(TreeNode* root) {
		 if (!root)   return true;
		 return abs(height(root->left) - height(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
	 }
	 int height(TreeNode* root) {
		 if (!root)   return 0;
		 return max(height(root->left), height(root->right)) + 1;
	 }
 };


 int main() {
	int num = numTrees(3);
	vector<TreeNode *> trees = generateTrees(3);
    int i = 0;
}