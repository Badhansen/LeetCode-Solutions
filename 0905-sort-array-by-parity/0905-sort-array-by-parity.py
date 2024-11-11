class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        s, e = 0, len(nums) - 1
        while s < e:
            if (nums[s] & 1) and (nums[e] & 1):
                e -= 1
            elif not (nums[s] & 1) and (nums[e] & 1):
                s += 1
            elif (nums[s] & 1) and not (nums[e] & 1):
                nums[s], nums[e] = nums[e], nums[s]
                s += 1
                e -= 1
            else:
                s += 1
        return nums