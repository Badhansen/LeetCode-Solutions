/*
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

// Time: O(n * min(n, m))
// Space: O(n * min(n, m))

*/
class Solution {
private:
    int mod = 1e9 + 7;
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(steps, arrLen);
        vector<int> prev(arrLen, 0), curr(arrLen, 0);
        prev[0] = 1;
        for (int s = 0; s < steps; s++) {
            curr = vector(arrLen, 0);
            for (int i = 0; i < arrLen; i++) {
                curr[i] = prev[i];
                if (i > 0) {
                    curr[i] = (curr[i] + prev[i - 1]) % mod;
                }
                if (i < arrLen - 1) {
                    curr[i] = (curr[i] + prev[i + 1]) % mod;
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};
// Time: O(n * min(n, m))
// Space: O(min(n, m))