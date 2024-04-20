class Solution:
    def climbStairs(self, n: int) -> int:
        dp = dict()
        
        def ways(i):
            if i == n:
                return 1
            if i > n:
                return 0
            if i in dp:
                return dp[i]
            dp[i] = ways(i + 1) + ways(i + 2)
            return dp[i]
        
        return ways(0)