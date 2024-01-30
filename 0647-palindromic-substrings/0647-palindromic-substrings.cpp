class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        bool dp[n + 1][n + 1];
        memset(dp, false, sizeof dp);
        int maxLength = 1, startIndex;
        
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        for(int i = 0; i + 1 < n; i++){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                maxLength = 2;
                startIndex = i;
            }
        }
        for(int l = 3; l <= n; l++){
            for(int i = 0; i < n - l + 1; i++){
                int j = i + l - 1;
                if(dp[i + 1][j - 1] && s[i] == s[j]){
                    dp[i][j] = true;
                }
            }
        }
        int count = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(dp[i][j] > 0) count++;
            }
        }
        return count;
    }
    int countSubstrings(string s) {
        return longestPalindrome(s);
    }
};