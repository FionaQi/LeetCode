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

vector<vector<int> > levelOrderBottom(TreeNode *root) {
	vector<vector<int>> result;
	if (root == NULL)
		return result;
	stack<vector<int>> res;
	vector<int> temp;
	queue<TreeNode *> que;
	que.push(root);
	int count = 1;
	int num = 0;
	while (!que.empty())
	{
		for (int i = 0; i < count; i++)
		{
			root = que.front();
			temp.push_back(root->val);
			if (root->left){
				que.push(root->left);
				num++;
			}
			if (root->right){
				que.push(root->right);
				num++;
			}
			que.pop();
		}
		res.push(temp);
		temp.clear(); //****
		count = num;
		num = 0;

	}
	while (!res.empty())
	{
		result.push_back(res.top());
		res.pop();
	}
	return result;
}

void main()
{
	TreeNode * r= new TreeNode(1);
	r->left = new TreeNode(2);
//	zigzagLevelOrder(r);

	int t = Numberof1s(11);
}