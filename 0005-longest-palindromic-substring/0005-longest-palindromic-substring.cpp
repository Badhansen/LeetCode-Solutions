class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        int start = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        for (int p = 3; p <= n; p++) {
            for (int i = 0; i < n - p + 1; i++) {
                int j = i + p - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (maxLength < p) {
                        start = i;
                        maxLength = p;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
};