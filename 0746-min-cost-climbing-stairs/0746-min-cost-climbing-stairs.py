class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = dict()
        def dfs(i: int) -> int:
            if i >= len(cost):
                return 0
            if i in dp:
                return dp[i]
            dp[i] = min(dfs(i + 1), dfs(i + 2)) + cost[i]
            return dp[i]
        return min(dfs(0), dfs(1))