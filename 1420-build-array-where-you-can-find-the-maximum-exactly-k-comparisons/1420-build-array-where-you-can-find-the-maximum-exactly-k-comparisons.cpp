class Solution {
public:
    int dp[55][105][55];
    int mod = 1e9 + 7;
    int n, m;
    int rec(int i, int maxSoFar, int remain) {
        if (i == n) {
            if (remain == 0) {
                return 1;
            }
            return 0;
        }
        if (remain < 0) {
            return 0;
        }
        int &res = dp[i][maxSoFar][remain];
        if (res != -1) {
            return res;
        }
        res = 0;
        for (int num = 1; num <= maxSoFar; num++) {
            res = (res + rec(i + 1, maxSoFar, remain) % mod) % mod;
        }
        for (int num = maxSoFar + 1; num <= m; num++) {
            res = (res + rec(i + 1, num, remain - 1) % mod) % mod;
        }
        return res;
    }
    int numOfArrays(int n, int m, int k) {
        this->n = n, this->m = m;
        memset(dp, -1, sizeof dp);
        return rec(0, 0, k);
    }
};