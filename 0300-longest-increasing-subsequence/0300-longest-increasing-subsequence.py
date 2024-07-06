class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1] * n
        def solve(pos, nums):
            if pos == len(nums):
                return 1
            if dp[pos] != -1:
                return dp[pos]
            res = 1
            for i in range(pos + 1, len(nums)):
                if nums[pos] < nums[i]:
                    res = max(res, 1 + solve(i, nums))
            dp[pos] = res
            return res
        return max([solve(i, nums) for i in range(n)])
    