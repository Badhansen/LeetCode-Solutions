class Solution:
    def minCost(self, nums: List[int], costs: List[int]) -> int:
        stack1, stack2 = [], []
        dp = [float('inf')] * len(nums)
        dp[0] = 0
        for i, n in enumerate(nums):
            while stack1 and n >= nums[stack1[-1]]:
                prev = stack1.pop()
                dp[i] = min(dp[i], dp[prev] + costs[i])
            while stack2 and n < nums[stack2[-1]]:
                prev = stack2.pop()
                dp[i] = min(dp[i], dp[prev] + costs[i])
            stack1.append(i)
            stack2.append(i)
        return dp[len(nums) - 1]