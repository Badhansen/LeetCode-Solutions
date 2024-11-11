class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []
        n = len(nums)
        i, j = 0, 0
        while i < n:
            j = i + 1
            while j < n:
                start = j + 1
                end = n - 1
                summation = target - nums[i] - nums[j]
                while start < end:
                    if nums[start] + nums[end] == summation:
                        res.append([nums[i], nums[j], nums[start], nums[end]])
                        third, fourth = nums[start], nums[end]
                        while start < end and nums[start] == third:
                            start += 1
                        while start < end and nums[end] == fourth:
                            end -= 1
                    elif nums[start] + nums[end] > summation:
                        end -= 1
                    else:
                        start += 1
                while j + 1 < n and nums[j + 1] == nums[j]: 
                    j += 1
                j += 1
            while i + 1 < n and nums[i + 1] == nums[i]: 
                i += 1
            i += 1
                
        return res