// @Author: KING-SEN
// @Author: KING-SEN

class Solution {
public:
    bool isValid(int x, int y, int r, int c) {
        if (x >= 0 && x < r && y >= 0 && y < c) {
            return true;
        }
        return false;
    }
    void dfs(int x, int y, vector<vector<int>>& grid) {
        if (!isValid(x, y, grid.size(), grid[0].size()) || grid[x][y] == 1) {
            return;
        }
        grid[x][y] = 1;
        dfs(x + 1, y, grid);
        dfs(x, y + 1, grid);
        dfs(x - 1, y, grid);
        dfs(x, y - 1, grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        // 1st and last Row visit
        for (int i = 0; i < c; i++) {
            if (grid[0][i] == 0) {
                dfs(0, i, grid);
            }
            if (grid[r - 1][i] == 0) {
                dfs(r - 1, i, grid);
            }
        }
        // 1st and last Column visit
        for (int i = 0; i < r; i++) {
            if (grid[i][0] == 0) {
                dfs(i, 0, grid);
            }
            if (grid[i][c - 1] == 0) {
                dfs(i, c - 1, grid);
            }
        }
        int answer = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0) {
                    dfs(i, j, grid);
                    answer++;
                }
            }
        }
        return answer;
    }
};