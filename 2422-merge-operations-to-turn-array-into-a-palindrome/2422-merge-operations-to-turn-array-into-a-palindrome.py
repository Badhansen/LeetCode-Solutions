class Solution:
    # def minimumOperations(self, nums: List[int]) -> int:
    #     left, right = 0, len(nums) - 1
    #     res, lsum, rsum = 0, nums[left], nums[right]
    #     while left < right:
    #         if lsum < rsum:
    #             left += 1
    #             lsum += nums[left]
    #             res += 1
    #         elif lsum > rsum:
    #             right -= 1
    #             rsum += nums[right]
    #             res += 1
    #         else:
    #             left += 1
    #             right -= 1
    #             lsum = nums[left]
    #             rsum = nums[right]
    #     return res
    
    def minimumOperations(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        res = 0
        while left < right:
            lsum, rsum = nums[left], nums[right]
            while left < right and lsum != rsum:
                res += 1
                if lsum < rsum:
                    left += 1
                    lsum += nums[left]
                else:
                    right -= 1
                    rsum += nums[right]
            if lsum == rsum:
                left += 1
                right -= 1
        return res
        return res