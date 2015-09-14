#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution{
 public:
	 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		 return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	 }

	 TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
		 return build2(preorder, inorder, 0, preorder.size(), 0, inorder.size());
	 }
 private:
	 template <typename InputIterator>
	 TreeNode* build(InputIterator preFirst, InputIterator preLast, InputIterator inFirst, InputIterator inLast) {
		 if (preFirst == preLast) return NULL;
		 if (inFirst == inLast) return NULL;
		 TreeNode * root = new TreeNode(*preFirst);
		 auto inRootPos = find(inFirst, inLast, root->val);
		 int leftLen = distance(inFirst, inRootPos);
		 root->left = build(next(preFirst), next(preFirst, leftLen + 1), inFirst, inRootPos);
		 root->right = build(next(preFirst, leftLen + 1), preLast, next(inRootPos), inLast);
		 return root;
	 }

	 TreeNode* build2(vector<int>& preorder, vector<int>& inorder, int preFirst, int preLast, int inFirst, int inLast) {
		 if (preFirst == preLast) return NULL;
		 if (inFirst == inLast) return NULL;
		 TreeNode * root = new TreeNode(preorder[preFirst]);
		 auto inRootPos = find(next(inorder.begin(), inFirst), next(inorder.begin(), inLast), root->val);
		 int leftLen = distance(next(inorder.begin(), inFirst), inRootPos);
		 root->left = build2(preorder, inorder, preFirst + 1, preFirst + leftLen + 1, inFirst, inFirst + leftLen);
		 root->right = build2(preorder, inorder, preFirst + leftLen + 1, preLast, inFirst + leftLen, inLast);
		 return root;
	 }
 };

 int main() {
	int pre[] = {1,2,4,5,3,6};
	int in[] = {4,2,5,1,3,6};
	int post[] = {4,5,2,6,3,1};
	vector<int> preorder(pre, pre+sizeof(pre)/sizeof(int));
	vector<int> inorder(in, in + sizeof(in)/sizeof(int));
	vector<int> postorder(post, post+sizeof(post)/sizeof(int));
	TreeNode * res = buildTree(preorder, inorder);
    int i = 0;
}