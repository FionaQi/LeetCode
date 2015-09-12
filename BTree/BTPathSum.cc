#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> res;
    vector<int> cur;
    pathSum(root, sum, res, cur);
    return res;
}

void pathSum(TreeNode * root, int sum, vector<vector<int>> &paths, vector<int> &curpath) {
    if(!root)   return;
    curpath.push_back(root->val);
    
    if(!root->left && !root->right && sum == root->val) {
        paths.push_back(curpath);
    }
    
    if(root->left)  
        pathSum(root->left, sum - root->val, paths, curpath);
    if(root->right)
        pathSum(root->right, sum - root->val, paths, curpath);
    
    curpath.pop_back();
}