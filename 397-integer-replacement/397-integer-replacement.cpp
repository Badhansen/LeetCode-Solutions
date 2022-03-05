// @Author: KING-SEN

class Solution {
private:
    unordered_map<int, int> dp;
public:
    int solve(long n){
        if(n == 1) return 0;
        if(dp.count(n)){
            return dp[n];
        }
        if(!(n & 1)){
            dp[n] = 1 + solve(n / 2);
        }
        else{
            dp[n] = 1 + min(solve(n - 1), solve(n + 1));
        }
        return dp[n];
    }
        
    int integerReplacement(int n) {
        return solve(n);
    }
};