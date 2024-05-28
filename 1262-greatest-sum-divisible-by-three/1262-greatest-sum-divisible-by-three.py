class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = {}
        def solve(pos, mod):
            if pos == len(nums):
                if mod == 0:
                    return 0
                return float("-inf")
            if (pos, mod) in dp:
                return dp[(pos, mod)]
            taken = nums[pos] + solve(pos + 1, (mod + nums[pos]) % 3)
            notTaken = solve(pos + 1, mod)
            dp[(pos, mod)] = max(taken, notTaken)
            return dp[(pos, mod)]
        return solve(0, 0)
            
                