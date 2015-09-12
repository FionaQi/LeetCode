#include <iostream>
#include <string>
#include <vector>
using namespace std;
class NQueens{
public:
	int N;
	vector<vector<string> > solveNQueens(int n) {
		this->N = n;
		for (int i = 0; i < n; i++) {
			string ma(n, '.');
			map.push_back(ma);
		}
		putQueen(0);
		return res;
	}
private:
	vector<vector<string> > res;  //total count
	vector<string> map;
	void putQueen(int row) {
		if (row == N) {
			res.push_back(map);
			print();
			return;
		}
		for (int i = 0; i < N; i++) {   //i:col
			if (isOK(row, i)) {
				map[row][i] = 'Q';
				putQueen(row + 1);
				map[row][i] = '.';
			}

		}
	}
	bool isOK(int x, int y) {   //row, col
		for (int i = 0; i < N; i++) {    //rows
			for (int j = 0; j < N; j++) {    //colomns
				// colomn reuse/ row / 
				if (x == i || y == j || j - i == y - x || x + y == i + j) {
					if (map[i][j] == 'Q') {
						return false;
					}
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