class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        mask = 0
        for i, n in enumerate(nums):
            mask ^= n
            mask ^= (i + 1)
        return mask