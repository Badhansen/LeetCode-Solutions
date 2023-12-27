// Iterative solution
class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        vector<int> dp(len + 1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ?  0 : 1;
        for (int i = 2; i <= len; i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            int number = stoi(s.substr(i - 2, 2));
            if (number >= 10 && number <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[len];
    }
};

// Time: O(N)
// Space: O(N)