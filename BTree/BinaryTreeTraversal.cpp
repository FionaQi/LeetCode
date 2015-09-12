#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if(!root)   return res;
    stack<const TreeNode *> sta;
    sta.push(root);
    while(!sta.empty()) {
        const TreeNode *p = sta.top();
        sta.pop();
        res.push_back(p->val);
        
        if(p->right)    sta.push(p->right);
        if(p->left)     sta.push(p->left);
    }
    return res;
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    const TreeNode *p = root;
    stack<const TreeNode *> s;
    s.push(p);
    while(!s.empty() ) {
        if(p!= NULL) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            result.push_back(p->val);
            p = p->right;
        }
    }
    return result;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    const TreeNode *visiting, *visited;
    visiting = root;
    stack<const TreeNode *> s;
    do {
        while(visiting != NULL) {
            s.push(visiting);
            visiting = visiting->left;
        }
        visited = NULL;
        while(!s.empty()) {
            visiting = s.top();
            s.pop();
            if(visiting->right == visited) {
                result.push_back(visiting->val);
                visited = visiting;
            } else {
                s.push(visiting);
                visiting = visiting->right;
                break;
            }
        }
    } while(!s.empty());
    return result;
}
    
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)   return res;
    vector<int> temp;
    queue<TreeNode*> current, next;
    current.push(root);
    while(!current.empty()) {
        while(!current.empty()) {
            TreeNode * cur = current.front();
            temp.push_back(cur->val);
            if(cur->left)   next.push(cur->left);
            if(cur->right)  next.push(cur->right);
            current.pop();
        }
        res.push_back(temp);
        temp.clear();
        swap(current, next);
    }
    return res;
}    

int main() {
    TreeNode first(1);
    first.left = new TreeNode(2);
    first.right = new TreeNode(3);
    first.left->left = new TreeNode(4);
    first.left->right = new TreeNode(5);
    first.right->right = new TreeNode(6);
    
    std::vector<int> res = inorderTraversal(&first);
    std::cout << "Hello World!" << std::endl;
}
