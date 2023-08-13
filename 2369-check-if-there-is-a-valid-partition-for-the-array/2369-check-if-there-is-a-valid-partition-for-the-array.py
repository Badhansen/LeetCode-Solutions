class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        dp = {}
        def func(idx):
            if idx >= len(nums) - 1:
                return idx == len(nums)
            if idx in dp:
                return dp[idx]
            two = nums[idx] == nums[idx + 1]
            three = False
            if idx + 2 < len(nums):
                three = (two and nums[idx + 1] == nums[idx + 2]) or (nums[idx] + 1 == nums[idx + 1] and nums[idx] + 2 == nums[idx + 2])
            dp[idx] = (two and func(idx + 2)) or (three and func(idx + 3))
            return dp[idx]
        return func(0)