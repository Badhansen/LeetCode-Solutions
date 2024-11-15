class Solution:
    def findLengthOfShortestSubarray(self, nums: List[int]) -> int:
        right = len(nums) - 1
        while right > 0 and nums[right] >= nums[right - 1]:
            right -= 1
        ans = right
        left = 0
        while left < right and (left == 0 or nums[left - 1] <= nums[left]):
            while right < len(nums) and nums[left] > nums[right]:
                right += 1
            ans = min(ans, right - left - 1)
            """
            0 1 1 0 0 2 2
            0 1 2 3 4 5 6
            ans = 5 - 0 - 1
            """
            left += 1
            
        return ans
        