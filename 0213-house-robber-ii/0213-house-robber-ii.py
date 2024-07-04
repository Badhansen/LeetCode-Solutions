# class Solution:
#     def rob(self, nums: List[int]) -> int:
#         n = len(nums)
#         if n == 1:
#             return nums[0]
#         dp = [-1] * n
#         def dfs(i, n):
#             if i >= n:
#                 return 0
#             if dp[i] != -1:
#                 return dp[i]
#             rob = nums[i] + dfs(i + 2, n)
#             not_rob = dfs(i + 1, n)
#             dp[i] = max(rob, not_rob)
#             return dp[i]
#         res = dfs(0, n - 1)
#         dp = [-1] * n
#         print(dp)
#         res = max(res, dfs(1, n))
#         return res

class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        return max(self.calculate(nums[:-1]), self.calculate(nums[1:]))
    
    def calculate(self, nums):
        prev = 0
        prevprev = 0
        for n in nums:
            best = max(prevprev + n, prev)
            prevprev = prev
            prev = best
        return max(prev, prevprev)
        
        