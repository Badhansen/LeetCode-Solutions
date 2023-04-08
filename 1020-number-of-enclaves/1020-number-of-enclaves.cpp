class Solution {
public:
    bool isValid(int x, int y, int r, int c) {
        if (x >= 0 && x < r && y >= 0 && y < c) {
            return true;
        }
        return false;
    }
    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (!isValid(x, y, grid.size(), grid[0].size()) || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0;
        int result = dfs(x + 1, y, grid);
        result += dfs(x, y + 1, grid);
        result += dfs(x - 1, y, grid);
        result += dfs(x, y - 1, grid);
        return result + 1;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        // 1st and last Row visit
        for (int i = 0; i < c; i++) {
            if (grid[0][i] == 1) {
                dfs(0, i, grid);
            }
            if (grid[r - 1][i] == 1) {
                dfs(r - 1, i, grid);
            }
        }
        // 1st and last Column visit
        for (int i = 0; i < r; i++) {
            if (grid[i][0] == 1) {
                dfs(i, 0, grid);
            }
            if (grid[i][c - 1] == 1) {
                dfs(i, c - 1, grid);
            }
        }
        int answer = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    answer += dfs(i, j, grid);
                }
            }
        }
        return answer;
    }
};