// @Author: KING-SEN
// 1 last try
/*
class Solution {
private:
    int dp[205][205];
public:
    int solve(int low, int high){
        if(low >= high) return 0;
        if(dp[low][high] != -1) return dp[low][high];
        int globalMin = INT_MAX;
        for(int x = low; x <= high; x++){
            int localMax = x + max(solve(low, x - 1), solve(x + 1, high));
            globalMin = min(localMax, globalMin);
        }
        return dp[low][high] = globalMin; 
    }
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof dp); 
        return solve(1, n);
    }
};

*/
class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[205][205];
        memset(dp, 0, sizeof dp);
        for(int l = n; l > 0; l--){
            for(int r = l + 1; r <= n; r++){
                dp[l][r] = INT_MAX;
                for(int pick = l; pick <= r; pick++){
                    int left = dp[l][pick - 1];
                    int right = dp[pick + 1][r];
                    dp[l][r] = min(dp[l][r], pick + max(left, right));
                }
            }
        }
        return dp[1][n];
    }
};

// Time: O(N * N * N)
// Space: O(N * N)