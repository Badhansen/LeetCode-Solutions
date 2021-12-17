class Solution {
private:
    vector<int> dp;
public:
    int climbStairs(int n) {
        dp.resize(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// Assume that N = number of elements
// Time Complexity: O(N)
// Space Complexity: O(N)