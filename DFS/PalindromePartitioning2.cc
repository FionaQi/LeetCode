#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		this->minNum = 0;
		int n = s.size();
		if (n == 0)	return 0;
		bfs(s, 0, n);
		return this->minNum -1;
	}
private:
	int minNum;
	queue<int> curLevel;  // store where to cut
	queue<int> lastLevel;
	unordered_map<string, bool> mem;
	void bfs(string s, int left, int right){
		if (right == left){
			return;
		}
		pass(s, left, right);
		if (!curLevel.empty()) {
			swap(curLevel, lastLevel);
			this->minNum++;
		}

		while (!lastLevel.empty()) {
			left = lastLevel.front();
			lastLevel.pop();
			if (right == left){
				return;
			}
			pass(s, left, right);
			if (lastLevel.empty()) {
				swap(lastLevel, curLevel);
				this->minNum++;
			}
		}
	}
	void pass(string s, int left, int right) {
		for (int i = left + 1; i <= right; i++) {
			string ls = s.substr(left, i);
			if (getOrSet(ls)) {
				curLevel.push(i);
			//	bfs(s, i, right);
			}
		}
	}

	bool getOrSet(string s) {
		if (mem.find(s) != mem.end()) {
			return mem[s];
		}
		else {
			return mem[s] = isPalindrom(s);
		}
	}
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
};

int main() {
	Solution s;
	int res = s.minCut("aaaaaaaaaaaaa");   //time limit exceed
	return 0;
}