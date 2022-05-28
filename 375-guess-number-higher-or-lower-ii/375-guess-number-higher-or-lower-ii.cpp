// @Author: KING-SEN
// 1 last try

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