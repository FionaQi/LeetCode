#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
bool isOK(vector<vector<char>> &b, int x, int y, char val) {
	for(int i = 0; i < 9 ; i++) {
		if(i != x && b[y][i] == val)	
			return false;
	}
	for(int j = 0; j < 9 ; j++) {
		if(j != y && b[j][x] == val)	
			return false;
	}
	int blockX = x/3;
	int blockY = y/3;
	for(int i = blockX * 3; i <= blockX * 3 + 2 ; i++) {
		for(int j = blockY * 3; j <= blockY * 3 + 2; j++) {
			if(( i != x || j != y ) && b[j][i] == val)	
				return false;
		}
	}
	return true;
}

bool solve(vector<vector<char>> &board) {
    for(int i = 0; i < 9 ; i++) {
    	for(int j = 0; j < 9 ; j++) {
    		if(board[i][j] == '.') {
    			for(char k = '1'; k <= '9'; k++) {
    				board[i][j] = k;
    				if(isOK(board, j, i, k) && solve(board))
    					return true;
    				board[i][j] = '.';
    			}
    			return false;
    		}
    	}
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
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