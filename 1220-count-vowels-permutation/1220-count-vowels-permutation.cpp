class Solution {
public:
    long long dp[20001][6];
    const int mod = 1e9 + 7;
    long long rec(int i, int j){
        if(i == 1) return 1;
        long long &ret = dp[i][j];
        if(ret != 0) return ret;
        ret = 0;
        switch(j){
            case 0:
                ret = rec(i - 1, 1) % mod;
                break;
            case 1: 
                ret = (rec(i - 1, 0) + rec(i - 1, 2)) % mod;
                break;
            case 2:
                ret = (rec(i - 1, 0) + rec(i - 1, 1) + rec(i - 1, 3) + rec(i - 1, 4)) % mod;
                break;
            case 3:
                ret = (rec(i - 1, 2) + rec(i - 1, 4)) % mod;
                break;
            case 4:
                ret = rec(i - 1, 0) % mod;
                break;
        }
        return ret;
    }
    int countVowelPermutation(int n) {
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 5; j++){
                dp[i][j] = 0;
            }
        }
        long long ans = 0;
        for(int i = 0; i < 5; i++){
            ans = (ans + rec(n, i)) % mod;
        }
        return ans;
    }
};