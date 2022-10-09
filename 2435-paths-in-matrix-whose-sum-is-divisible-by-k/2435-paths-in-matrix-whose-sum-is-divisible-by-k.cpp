const int kMod = 1e9 + 7;

class Solution {
private:
    vector<vector<int>> dp[50];
    int m, n, k;
public:
    int solve(int i, int j, int sum, vector<vector<int>>& grid) {
        if (i >= m || j >= n) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            if ((sum + grid[i][j]) % k == 0) 
                return 1;
            return 0;
        }
        int &ret = dp[sum % k][i][j];
        if (ret != -1) {
            return ret;
        }
        int right = solve(i, j + 1, sum + grid[i][j], grid);
        int down = solve(i + 1, j, sum + grid[i][j], grid);
        return ret = (right + down) % kMod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        this->k = k;
        for (int i = 0; i < 50; i++) {
            dp[i].resize(m + 1, vector<int>(n + 1, -1));
        }
        return solve(0, 0, 0, grid);
    }
};