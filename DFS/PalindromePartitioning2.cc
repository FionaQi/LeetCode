#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int partition(string s) {
		int n = s.size();
		if (n == 0)	return 0;
		partition(s, 0, n);
		return minNum;
	}
private:
	int minNum = INT_MAX;
	int curNum = -1;
	bool isPalindrom(string s, size_t left, size_t right) {
		while (left < right) {
			if (s[left] != s[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
	void partition(string s, int left, int right) {
		if (right == left){
			if( curNum < minNum )
				minNum = curNum;
			return;
		}
		for (int cut = left + 1; cut <= right; cut++) {
			if (isPalindrom(s, left, cut - 1)) {
				curNum++;
				partition(s, cut, right);
				curNum--;
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