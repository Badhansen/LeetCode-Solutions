class Solution {
public:
    int dp[501][501];
    int go(int i, int j, string& word1, string& word2){
        if(i == word1.size() || j == word2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ret = 0;
        if(word1[i] == word2[j]){
            ret = max(ret, 1 + go(i + 1, j + 1, word1, word2));
        }
        ret = max(ret, max(go(i + 1, j, word1, word2), go(i, j + 1, word1, word2)));
        return dp[i][j] = ret;
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        int ans = word1.size() + word2.size() - 2 * go(0, 0, word1, word2);
        return ans;
    }
};