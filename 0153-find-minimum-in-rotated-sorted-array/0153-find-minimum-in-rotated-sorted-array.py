class Solution:
    def findMin(self, nums: List[int]) -> int:
        low, high = 0, len(nums) - 1
        res = float('inf')
        while low <= high:
            mid = (low + high) // 2
            res = min(res, nums[mid])
            if nums[mid] < nums[-1]:
                high = mid - 1
            else:
                low = mid + 1
        return res