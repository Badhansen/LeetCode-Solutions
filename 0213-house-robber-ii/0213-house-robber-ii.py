class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        dp = [-1] * n
        def dfs(i, n):
            if i >= n:
                return 0
            if dp[i] != -1:
                return dp[i]
            rob = nums[i] + dfs(i + 2, n)
            not_rob = dfs(i + 1, n)
            dp[i] = max(rob, not_rob)
            return dp[i]
        res = dfs(0, n - 1)
        dp = [-1] * n
        res = max(res, dfs(1, n))
        return res