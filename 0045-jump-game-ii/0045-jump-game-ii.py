class Solution:
    def jump(self, nums: List[int]) -> int:
        # dp = [-1] * len(nums)
        # def solve(i):
        #     if i == len(nums) - 1:
        #         return 0
        #     if i >= len(nums):
        #         return float('inf')
        #     if dp[i] != -1:
        #         return dp[i]
        #     res = float('inf')
        #     for step in range(1, nums[i] + 1):
        #         res = min(res, 1 + solve(i + step))
        #     dp[i] = res
        #     return res
        # return solve(0)
        n = len(nums)
        endNode, farNode, count = 0, 0, 0
        for i in range(n - 1):
            # we continuously find the how far we can reach in the current jump
            farNode = max(farNode, i + nums[i])
            # if we have come to the end of the current jump,
            # we need to make another jump
            if i == endNode:
                count += 1
                endNode = farNode
        return count