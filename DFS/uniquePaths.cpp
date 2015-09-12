#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <string>
using namespace std;
    void dfs(vector<int> &nums, vector<bool> &visited, vector<int> &curpath, vector<vector<int>> &res) {
        if(curpath.size() == nums.size()) {
			if(find(res.begin(), res.end(), curpath) == res.end()) {
				res.push_back(curpath);
			}
            return;
        }
		int len = nums.size();
        for(int i = 0; i < len; i++) {
            if(visited[i] == 0) {
                curpath.push_back(i);
                visited[i] = 1;
                dfs(nums, visited, curpath, res);
                curpath.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0)
            return res;
        vector<int> curpath;
		vector<bool> visited(0, nums.size());
        dfs(nums, visited, curpath, res);
        return res;
    }


int main()
{
	char temp;
	vector<vector<char>> bo;
	freopen("suduku.txt","r",stdin);
	for(int i = 0; i < 9; i++) {
		vector<char> row;
		for(int j = 0; j < 9; j++) {
			if(cin >> temp) {
				row.push_back(temp);
			}
		}
		bo.push_back(row);
		row.clear();
	}
    solveSudoku(bo);
	fclose(stdin);
	return 0;
}