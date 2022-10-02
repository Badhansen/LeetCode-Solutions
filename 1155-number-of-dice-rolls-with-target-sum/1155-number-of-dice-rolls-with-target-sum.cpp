class Solution {
public:
    const int mod = 1e9 + 7;
    int D, F;
    int solve(int pos, int sum, vector<vector<int>>& dp){
        if(pos >= D){
            if(sum == 0) return 1;
            else return 0;
        }
        if(sum < 0) return 0;
        
        if(dp[pos][sum] != -1) 
            return dp[pos][sum];
        long long ret = 0;
        for(int i = 1; i <= F; i++){
            ret = (ret % mod + solve(pos + 1, sum - i, dp) % mod) % mod;
        }
        return dp[pos][sum] = ret % mod;
    }
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, -1));
        D = d, F = f;
        return solve(0, target, dp);
    }
};