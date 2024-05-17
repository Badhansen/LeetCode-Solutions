class Solution:
    def canJump(self, nums: List[int]) -> bool:
        res = nums[0]
        for i in range(1, len(nums)):
            if res < i:
                return False
            res = max(res, i + nums[i])
        return res >= len(nums) - 1