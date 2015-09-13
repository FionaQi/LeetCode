#include <iostream>
#include <string>
#include <vector>
using namespace std;
class NQueens{
public:
	vector<vector<string> > solveNQueens(int n) {
		this->N = n;
		this->map = vector<string>(n, string(n, '.'));
		dfs(0);
		return res;
	}
private:
	int N;
	vector<vector<string> > res;  //total count
	vector<string> map;
	void dfs(int row) {			//每次放一行
		if (row == this->N) {
			res.push_back(map);
			print();
			return;
		}
		for (int i = 0; i < N; i++) {   //i:col
			if (isOK(row, i)) {
				map[row][i] = 'Q';
				dfs(row + 1);
				map[row][i] = '.';
			}

		}
	}
	bool isOK(int row, int col) {  
		for (int i = 0; i < row; i++) {    //rows
			if (map[i][col] == 'Q') {
				return false;
			}
		}
		for (int i = 0; i < N; i++) {    
			if (row + col - i < N && row + col - i >= 0) {   
				if (map[i][row + col - i] == 'Q') {
					return false;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (i - row + col < N && i - row + col >= 0) {
				if (map[i][i - row + col] == 'Q') {
					return false;
				}
			}
		}
		return true;
	}
	void print() {
		for (int i = 0; i < N; i++) {
			cout << map[i] << endl;
		}
	}
};

int main() {
	cout << "in total count" << endl;
	NQueens q;
	vector<vector<string> > res = q.solveNQueens(4);
	return 0;
}