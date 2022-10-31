class Solution {
private:
    vector<vector<int>> direction_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visited_;
    int row_, col_;
public:
    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
        visited_[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int new_x = direction_[i][0] + x;
            int new_y = direction_[i][1] + y;
            if (new_x >= 0 && new_x < row_ && new_y >= 0 && new_y < col_ && grid[x][y] == grid[new_x][new_y] && !(new_x == px && new_y == py)) {
                if (visited_[new_x][new_y] || dfs(new_x, new_y, x, y, grid)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        row_ = grid.size(), col_ = grid[0].size();
        visited_.resize(row_, vector<bool>(col_, false));
        for (int i = 0; i < row_; i++) {
            for (int j = 0; j < col_; j++) {
                if (visited_[i][j] == false && dfs(i, j, -1, -1, grid)) {
                    return true;
                }
            }
        }
        return false;
    }
};