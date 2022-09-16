class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(1001, vector<int>(1001, 0));
        for (int op = m - 1; op >= 0; op--) {
            for (int left = op; left >= 0; left--) {
                dp[op][left] = max(multipliers[op] * nums[left] + dp[op + 1][left + 1],
                                   multipliers[op] * nums[n - 1 - (op - left)] + dp[op + 1][left]);
            }
        }
        return dp[0][0];
    }
};