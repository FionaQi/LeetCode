#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<string> > partition(string s) {
		int n = s.size();
		if (n >= 1)
			dfs(s, 0, n);
		return res;
	}
private:
	vector<vector<string> > res;
	vector<string> path;
	bool isPalindrom(string s) {
		int left = 0;
		int right = s.size() - 1;
		if (right < 0)
			return false;
		while (left < right) {
			if (s[left] != s[right]) {
				return false;
			}
			else {
				left++;
				right--;
			}
		}
		return true;
	}
	void dfs(string s, int left, int right) {
		if (right == left){
			res.push_back(path);
			return;
		}
		for (int i = left + 1; i <= right; i++) {
			string ls = s.substr(left, i - left);
			if (isPalindrom(ls)) {
				path.push_back(ls);
				dfs(s, i, right);
				path.pop_back();
			}
		}
	}
};

int main() {
	Solution s;
	vector<vector<string> > res = s.partition("aab");
	if (res.size()){
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++) {
				cout << res[i][j] << ", ";
			}
			cout << endl;
		}

	}

	return 0;
}