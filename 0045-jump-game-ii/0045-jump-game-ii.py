class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [-1] * len(nums)
        def solve(i):
            if i == len(nums) - 1:
                return 0
            if i >= len(nums):
                return float('inf')
            if dp[i] != -1:
                return dp[i]
            res = float('inf')
            for step in range(1, nums[i] + 1):
                res = min(res, 1 + solve(i + step))
            dp[i] = res
            return res
        return solve(0)