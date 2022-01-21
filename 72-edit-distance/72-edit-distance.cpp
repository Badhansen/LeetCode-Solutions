class Solution {
public:
    int rec(string &a, string &b){
        int n = a.size(), m = b.size();
        int dp[n + 1][m + 1];
        int result = 0; 
        for(int i = 0; i <= n; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i <= m; i++){
            dp[0][i] = i; 
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1;  j <= m; j++){
                if(a[i - 1] == b[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
                    
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int ret = rec(word1, word2);
        return ret;
    }
};