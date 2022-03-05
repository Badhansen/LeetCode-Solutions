// @Author: KING-SEN

class Solution {
public:
    const static int MAX_LEN = 127;
    const static int MAX_CHAR = 26;
    
    vector<vector<int>> dp;
    int len, k;
    
    int calculateLen(int n){
        return n == 1 ? 0 : n < 10 ? 1 : n < 100 ? 2 : 3;
    }
    int solve(int left, int k, string& str){
        if(k < 0){
            return MAX_LEN;
        }
        if(left >= len || len - left <= k){
            return 0;
        }
        int &res = dp[left][k];
        if(res != -1){
            return res;
        }
        res = MAX_LEN;
        int cnt[MAX_CHAR] = {0};
        // we try to make s[left:j] (both inculded) as one group,
        // and all chars in this group should be the same.
        // so we must keep the most chars in this range and remove others
        // the range length is (j - left + 1)
        // and the number of chars we need to remove is (j - left + 1 - most)
        for(int i = left, most = 0; i < len; i++){
            most = max(most, ++cnt[str[i] - 'a']);
            res = min(res, 1 + calculateLen(most) + solve(i + 1, k - (i - left + 1 - most), str));
        }
        return res;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        len = s.size(), this->k = k;
        dp.resize(len + 1, vector<int>(k + 1, -1));
        return solve(0, k, s);
    }
};