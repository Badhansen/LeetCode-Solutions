class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        std::vector<int> memo(n + 1);
        memo[0] = 0, memo[1] = 1, memo[2] = 2;
        for (int i = 3; i <= n; i++) {
            memo[i] = memo[i - 2] + memo[i - 1];
        }
        return memo[n];
    }
};