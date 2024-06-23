class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = {}
        def dfs(i):
            if i >= len(nums):
                return 0
            if i in dp:
                return dp[i]
            rob = nums[i] + dfs(i + 2)
            not_rob = dfs(i + 1)
            dp[i] = max(rob, not_rob)
            return dp[i]
        return dfs(0)