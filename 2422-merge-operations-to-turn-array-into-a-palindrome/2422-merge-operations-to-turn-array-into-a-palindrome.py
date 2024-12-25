class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        res, lsum, rsum = 0, nums[left], nums[right]
        while left < right:
            if lsum < rsum:
                left += 1
                lsum += nums[left]
                res += 1
            elif lsum > rsum:
                right -= 1
                rsum += nums[right]
                res += 1
            else:
                left += 1
                right -= 1
                lsum = nums[left]
                rsum = nums[right]
        return res