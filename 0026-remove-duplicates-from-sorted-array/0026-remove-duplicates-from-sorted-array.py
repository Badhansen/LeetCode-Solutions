class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        left, n = 1, len(nums)
        for right in range(1, n):
            if nums[right] != nums[right - 1]:
                nums[left] = nums[right]
                left += 1
        return left