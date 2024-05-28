class Solution:
    # def maxSumDivThree(self, nums: List[int]) -> int:
    #     dp = {}
    #     def solve(pos, mod):
    #         if pos == len(nums):
    #             if mod == 0:
    #                 return 0
    #             return float("-inf")
    #         if (pos, mod) in dp:
    #             return dp[(pos, mod)]
    #         taken = nums[pos] + solve(pos + 1, (mod + nums[pos]) % 3)
    #         notTaken = solve(pos + 1, mod)
    #         dp[(pos, mod)] = max(taken, notTaken)
    #         return dp[(pos, mod)]
    #     return solve(0, 0)
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [0, 0, 0]
        for num in nums:
            curr = dp[:]
            for i in range(3):
                mod = (curr[i] + num) % 3
                dp[mod] = max(dp[mod], curr[i] + num)
        return dp[0]
            
                