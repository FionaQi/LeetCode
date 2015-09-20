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
	TreeNode *sortedArrayToBST(vector<int> &num){
		TreeNode * root = NULL;
		const int n = num.size();
		if (n == 0)	return root;

		root = new TreeNode(0);
		createBST(root, num, 0, n - 1);
		return root;
	}
private:
	void createBST(TreeNode *root, vector<int> &ordered_array, int start, int end)  //前序
	{
		if (start <= end){
			//root赋值
			const int mid = (start + end) >> 1;
			root->val = ordered_array[mid];
			//新建left
			if (start <= mid - 1){
				root->left = new TreeNode(0);
				createBST(root->left, ordered_array, start, mid - 1);
			}
			//新建right
			if (mid + 1 <= end){
				root->right = new TreeNode(0);
				createBST(root->right, ordered_array, mid + 1, end);
			}
		}
	}
};

 int main() {
	 int a[] = { 1, 2, 3, 4, 5 };
	 vector<int> num = vector<int>(a, a + 5);
	TreeNode *trees = sortedArrayToBST(num);
    int i = 0;
}