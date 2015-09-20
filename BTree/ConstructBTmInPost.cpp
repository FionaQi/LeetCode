#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

template <typename Iterator>
TreeNode* build(Iterator inFirst, Iterator inLast, Iterator postFirst, Iterator postLast) {
    if(postFirst == postLast) return NULL;
    if(inFirst == inLast) return NULL;
    TreeNode *root = new TreeNode(*prev(postLast));
    auto inRootPos = find(inFirst, inLast, root->val);
    int leftLen = distance(inFirst, inRootPos);
    root->left = build(inFirst, inRootPos, postFirst, next(postFirst, leftLen));
    root->right = build(next(inRootPos), inLast, next(postFirst, leftLen), prev(postLast));
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}

 int main() {
	int pre[] = {1,2,4,5,3,6};
	int in[] = {4,2,5,1,3,6};
	int post[] = {4,5,2,6,3,1};
	vector<int> preorder(pre, pre+sizeof(pre)/sizeof(int));
	vector<int> inorder(in, in + sizeof(in)/sizeof(int));
	vector<int> postorder(post, post+sizeof(post)/sizeof(int));
	TreeNode * res = buildTree(inorder, postorder);
    int i = 0;
}