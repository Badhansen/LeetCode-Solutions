class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if ((mid - 1 < 0 or nums[mid - 1] != nums[mid]) and 
                (mid + 1 == len(nums) or nums[mid] != nums[mid + 1])):
                    return nums[mid]
            leftSize = mid - 1 if nums[mid - 1] == nums[mid] else mid
            if leftSize % 2 != 0:
                right = mid - 1
            else:
                left = mid + 1
        return -1