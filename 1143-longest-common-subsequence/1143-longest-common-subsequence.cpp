// @Author: KING-SEN

class Solution {
private:
    vector<vector<int>> dp;
public:
    int lcs(int p1, int p2, string& text1, string& text2){
        if(p1 < 0 || p2 < 0){
            return 0;
        }
        int &ret = dp[p1][p2];
        if(ret != -1){
            return ret;
        }
        if(text1[p1] == text2[p2]){
            ret = 1 + lcs(p1 - 1, p2 - 1, text1, text2);
        }
        else{
            ret = max(lcs(p1 - 1, p2, text1, text2), lcs(p1, p2 - 1, text1, text2));
        }
        return ret;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        dp.resize(len1 + 1, vector<int>(len2, -1));
        return lcs(len1 - 1, len2 - 1, text1, text2);
    }
};