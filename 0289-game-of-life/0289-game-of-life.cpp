class Solution {
private:
    vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
public:
    
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int count = 0;
                for (auto dir : directions) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        if (board[x][y] & 1) {
                            count++;
                        }
                    }
                }
                board[i][j] |= (count << 1);
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int value = board[i][j] & 1, count = (board[i][j] >> 1);
                //cout << value << " " << count << endl;
                if (value && (count < 2 || count > 3))  {
                    board[i][j] = 0;
                } else if (value && (count == 2 || count == 3)) {
                    board[i][j] = value ? 1 : 0;
                } else if (count == 3 && !value) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};