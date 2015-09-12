#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->M = obstacleGrid.size();
        if(this->M < 1)   return 0;
        this->N = obstacleGrid[0].size();
        this->mem = vector<vector<int>> (this->M+1, vector<int> (this->N+1, 0));
        return dfs(obstacleGrid, this->M, this->N);
    }
private:
    vector<vector<int>> mem;
    int M;
    int N;
    int dfs(vector<vector<int>>& obstacleGrid, int m, int n) {
        if(m < 1 || n < 1)  return 0;
        if(m == 1 && n == 1)    return 1;
		cout << M-(m-1) << " " << N-n << "; " << M-m << " " << N-(n-1) << endl;
        if(obstacleGrid[M-(m-1)][N-n] == 1 && obstacleGrid[M-m][N-(n-1)] == 1 ){
			return 0;
		}
        else if(obstacleGrid[M-(m-1)][N-n] == 1)    return getOrSetValue(obstacleGrid, m, n-1);
        else if(obstacleGrid[M-m][N-(n-1)] == 1)    return getOrSetValue(obstacleGrid, m-1, n);
        else    return getOrSetValue(obstacleGrid, m-1, n) + getOrSetValue(obstacleGrid, m, n-1);
    }
    int getOrSetValue(vector<vector<int>>& obstacleGrid, int m, int n) {
        if(mem[m][n] > 0)   return mem[m][n];
        else {
            mem[m][n] = dfs(obstacleGrid, m,n);
            return  mem[m][n];
        }
    }
};

int main() {
	Solution s;
	int res = s.uniquePathsWithObstacles( vector<vector<int>> (1, vector<int> (2, 0)));

	return 0;
}