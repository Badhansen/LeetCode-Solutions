// @Author: KING-SEN

class Solution {
public:
    int row = 0, column = 0;
    map<string, bool> dp;
    bool Dfs(int r, int c, int sum, vector<vector<int>>& grid) {
        if (r >= row || c >= column) {
            return false;
        }
        string key = to_string(r) + "|" + to_string(c) + "|" + to_string(sum);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        sum += grid[r][c] == 1 ? 1 : -1;
        if (r == row - 1 && c == column - 1) {
            return sum == 0;
        }
        return dp[key] = Dfs(r + 1, c, sum, grid) || Dfs(r, c + 1, sum, grid);
    }
    bool isThereAPath(vector<vector<int>>& grid) {
        row = grid.size();
        column = grid[0].size();
        if ((row + column - 1) % 2 != 0) {
            return false;
        }
        return Dfs(0, 0, 0, grid);
    }
};