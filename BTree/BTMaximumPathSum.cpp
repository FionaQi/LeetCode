#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 int sum = 0;

void dfs(TreeNode * root, int pathsum) {
    if(!root)   return;
    pathsum += root->val;
    
    if(!root->left && !root->right) {
        sum += pathsum;
    }
    
    if(root->left)  
        dfs(root->left, pathsum);
    if(root->right)
        dfs(root->right, pathsum);
    
    pathsum -= root->val;
}

int maxPathSum(TreeNode *root) {
    int pathsum = 0;
    dfs(root, pathsum);
    return sum;
}
int main() {
	TreeNode first(1);
    first.left = new TreeNode(2);
    first.right = new TreeNode(3);
    first.left->left = new TreeNode(4);
    first.left->right = new TreeNode(5);
    first.right->right = new TreeNode(6);
	int res = maxPathSum(&first);
	return 0;
}