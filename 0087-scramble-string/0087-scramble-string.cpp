class Solution {
private:
    int dp[35][35][35];
    bool vis[35][35][35];
public:
    bool solve(int i, int j, int len, string &s1, string &s2) {
        /*
    s1, s2 is scramble when
        s1[0:k], s2[0:k] is scramble and s1[k:n], s2[k:n] is scramble.
    Or,
        s1[0:k], s2[n-k:n] is scramble and s1[k:n], s2[0:n-k] is scramble.
    */
        if (vis[i][j][len]) {
            return dp[i][j][len];
        }
        if (len == 1) {
            return dp[i][j][len] = s1[i] == s2[j];
        }
        for (int k = 1; k < len; k++) {
            if (solve(i, j, k, s1, s2) && solve(i + k, j + k, len - k, s1, s2)) {
                return dp[i][j][len] = true;
            }
            if (solve(i, j + len - k, k, s1, s2) && solve(i + k, j, len - k, s1, s2)) {
                return dp[i][j][len] = true;
            }
        }
        vis[i][j][len] = true;
        return dp[i][j][len] = false;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        memset(dp, -1, sizeof(dp));
        memset(vis, false, sizeof(vis));
        return solve(0, 0, n, s1, s2);
    }
};