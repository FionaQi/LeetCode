#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 bool isSymmetric(TreeNode* root) {
	 if (!root)   return true;
	 stack<TreeNode*> leftT;
	 stack<TreeNode*> rightT;
	 leftT.push(root->left);
	 rightT.push(root->right);
	 while (!leftT.empty()) {
		 TreeNode *l = leftT.top();
		 TreeNode *r = rightT.top();
		 leftT.pop();
		 rightT.pop();
		 if (!l && !r)            continue;
		 if (!l || !r)            return false;
		 if (l->val != r->val)    return false;

		 leftT.push(l->left);
		 rightT.push(r->right);

		 leftT.push(l->right);
		 rightT.push(r->left);
	 }
	 return true;
 }

 int main() {
    int i = 0;
}