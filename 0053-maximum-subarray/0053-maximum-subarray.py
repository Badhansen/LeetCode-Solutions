class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res, curr = float("-inf"), 0
        for n in nums:
            curr += n
            res = max(res, curr)
            if curr < 0:
                curr = 0
        return res