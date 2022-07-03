class Solution {
private:
    const int mod = 1e9 + 7;
    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};
    int dp[1005][1005];
    int n, m;
public:
    int solve(int r, int c, vector<vector<int>>& grid){
        int &ret = dp[r][c];
        if(ret != -1) return ret;
        ret = 1;
        for(int i = 0; i < 4; i++){
            int nr, nc;
            nr = x[i] + r;
            nc = y[i] + c;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                if(grid[r][c] < grid[nr][nc]){
                    ret = (ret + solve(nr, nc, grid)) % mod;
                }
            }
        }
        return ret % mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof dp);
        long ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = (ans + solve(i, j, grid)) % mod;
            }
        }
        return ans;
    }
};