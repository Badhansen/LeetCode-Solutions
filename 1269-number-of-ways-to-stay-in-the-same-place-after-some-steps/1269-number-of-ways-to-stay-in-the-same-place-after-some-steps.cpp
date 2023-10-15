class Solution {
private:
    int mod = 1e9 + 7;
    int dp[505][505];
    int N;
public:
    int dfs(int i, int steps) {
        if (steps == 0) {
            return i == 0;
        }
        int &res = dp[i][steps];
        if (res != -1) {
            return res;
        }
        res = dfs(i, steps - 1);
        if (i > 0) {
            res = (res + dfs(i - 1, steps - 1)) % mod;
        }
        if (i < N - 1) {
            res = (res + dfs(i + 1, steps - 1)) % mod;
        }
        return res;
    }
    int numWays(int steps, int arrLen) {
        this->N = arrLen;
        memset(dp, -1, sizeof dp);
        int res = dfs(0, steps);
        return res;
    }
};