#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



vector<TreeNode *> createTrees(int start, int end) {
    vector<TreeNode *> result;
	if(start > end) {
        TreeNode *root = NULL;
		result.push_back(root);
        return result;
    }
    for(int i = start; i <= end; i++) {
        
        vector<TreeNode *> left = createTrees(start, i-1);
        vector<TreeNode *> right = createTrees(i+1, end);
        for(int l = 0; l < left.size(); l++) {
            for( int r = 0; r < right.size(); r++ ) {
                TreeNode * root = new TreeNode(i);
                root->left = left[l];
                root->right = right[r];
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode *> generateTrees(int n) {
    return createTrees(1, n);
}

int numTrees(int n) {
    if(n < 2) return 1;
    vector<int> f(n+1, 0);
    f[0] = 1;
    f[1] = 1;
	for(int m = 2; m < n+1 ; m++){
		for(int i = 0; i < m; i++){
			f[m] += f[i] * f[m-1-i];
		}
	}
    return f[n];
}
 int main() {
	int num = numTrees(3);
	vector<TreeNode *> trees = generateTrees(3);
    int i = 0;
}