class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int h = board.size();
        if(h = 2)  return;
        int w = board[0].size();
        for(int i = 0; i < w; i++){
            bfs(board, i, 0, w, h);
            bfs(board, i, h-1, w, h);
        }
        for(int j = 0; j < h; j++){
            bfs(board, 0, j, w, h);
            bfs(board, w-1, j, w, h);
        }
        
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                if(board[j][i] == '.') {
                    board[j][i] = 'O';
                } else  {
                    board[j][i] = 'X';
                }
            }
        }
    }
private:
    void bfs(vector<vector<char>> & board, int x, int y, int w, int h) {
        queue<pair<int, int>> que;
        pass(board, x+1, y, w, h, que);
        while(!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop();
            x = cur.first;
            y = cur.second;
            pass(board, x+1, y, w, h, que);
            pass(board, x-1, y, w, h, que);
            pass(board, x, y+1, w, h, que);
            pass(board, x, y-1, w, h, que);
        }
    }
    void pass(vector<vector<char>> &board, int x, int y, int w, int h, queue<pair<int, int>> &que) {
        if(x < 0 || x >= w || y < 0 || y >= h || board[y][x] != 'O') {
            return;
        }
        board[y][x] = '.';
        que.push(makepair(x, y));
    }
};