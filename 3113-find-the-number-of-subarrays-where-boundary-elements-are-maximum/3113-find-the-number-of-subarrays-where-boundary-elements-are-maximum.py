class Solution:
    def numberOfSubarrays(self, nums: List[int]) -> int:
        dp = {i: 1 for i in range(len(nums))}
        stack = []
        for i, n in enumerate(nums):
            while stack and n >= nums[stack[-1]]:
                j = stack.pop()
                if nums[j] == nums[i]:
                    dp[i] += dp[j]
            stack.append(i)
        return sum(dp.values())