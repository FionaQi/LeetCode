#include<iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> current, next;
        bool reverse = 0;
        vector<int> temp;
        vector<int> printcurrentlevel;
        current.push(root);
        while(!current.empty()){
            while(!current.empty()){
                TreeNode* cur = current.front();
                temp.push_back(cur->val);
                if(cur->left)   next.push(cur->left);
                if(cur->right)  next.push(cur->right);
                current.pop();
            }
            if(reverse){
                for(int i = temp.size()-1 ; i >= 0; --i )
                {
                    printcurrentlevel.push_back(temp[i]);
                }
                if(printcurrentlevel.size() != 0)
                    res.push_back(printcurrentlevel);
                reverse = 0;
            }
            else{
                res.push_back(temp);
                reverse = 1;
            }
            temp.clear();
            printcurrentlevel.clear();
            swap(current, next);
        }
        return res;
    }

int Numberof1s(int n)
{
	int cnt = 0;
	while(n){
		++cnt;
		n = (n-1) & n;
	}
	return cnt;
}
void main()
{
	TreeNode * r= new TreeNode(1);
	r->left = new TreeNode(2);
//	zigzagLevelOrder(r);

	int t = Numberof1s(11);
}