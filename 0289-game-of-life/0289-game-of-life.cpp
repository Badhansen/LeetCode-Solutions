class Solution {
private:
    vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
public:
    
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int count = 0;
                for (auto dir : directions) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        if (board[x][y]) {
                            count++;
                        }
                    }
                }
                if (board[i][j] && count < 2) {
                    res[i][j] = 0;
                } else if (board[i][j] && (count == 2 || count == 3)) {
                    res[i][j] = 1;
                } else if (board[i][j] && count > 3) {
                    res[i][j] = 0;
                } else if (!board[i][j] && count == 3) {
                    res[i][j] = 1;
                } 
            }
        }
        board = res;
    }
};