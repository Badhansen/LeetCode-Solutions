class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        int oneStep, twoStep;
        for(int i = 2; i <= n; i++){
            oneStep = cost[i - 1] + dp[i - 1];
            twoStep = cost[i - 2] + dp[i - 2];
            dp[i] = min(oneStep, twoStep);
        }
        return dp[n];
    }
};