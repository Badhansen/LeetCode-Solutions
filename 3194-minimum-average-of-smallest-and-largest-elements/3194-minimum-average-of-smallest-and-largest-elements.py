class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        n = len(nums)
        nums.sort()
        left, right, res = 0, n - 1, float('inf')
        while left <= right:
            res = min(res, (nums[left] + nums[right]) / 2.0)
            left += 1
            right -= 1
        return res