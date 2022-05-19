class Solution {
private:
    int dirx[4] = {0, 0, 1, -1};
    int diry[4] = {1, -1, 0, 0};
    int dp[201][201];
public:
    int solve(int r, int c, vector<vector<int>>& matrix){
        if(r == matrix.size() || c == matrix[0].size()){
            return 0;
        }
        int& ret = dp[r][c];
        if(ret != -1){
            return ret;
        }
        ret = 1;
        for(int d = 0; d < 4; d++){
            int nr = dirx[d] + r;
            int nc = diry[d] + c;
            if(nr >= 0 && nr < matrix.size() && nc >= 0 && nc < matrix[0].size() && matrix[r][c] < matrix[nr][nc]){
                ret = max(ret, 1 + solve(nr, nc, matrix));
            }
        }
        return ret;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[0].size(); c++){
                ans = max(ans, solve(r, c, matrix));
            }
        }
        return ans;
    }
};