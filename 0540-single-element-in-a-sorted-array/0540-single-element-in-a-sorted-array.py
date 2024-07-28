class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        maxMask = 0xFFFFFFFF
        mask = 0
        for n in nums:
            mask ^= n
            # mask &= maxMask
        return mask