class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        n = len(nums)
        result = 0
        for i in range(n):
            min_value, max_value = nums[i], nums[i]
            for j in range(i, n):
                min_value = min(min_value, nums[j])
                max_value = max(max_value, nums[j])
                result += (max_value - min_value)
        return result