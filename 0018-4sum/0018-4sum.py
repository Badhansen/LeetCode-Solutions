class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        self.res, self.quad = [], []
        self.kSum(4, nums, 0, target)
        return self.res
        
        return res
    # def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
    #     nums.sort()
    #     res = []
    #     n = len(nums)
    #     for i in range(n - 3):
    #         if i > 0 and nums[i] == nums[i - 1]:
    #             continue
    #         for j in range(i + 1, n - 2):
    #             if j > i + 1 and nums[j] == nums[j - 1]:
    #                 continue
    #             new_target = target - (nums[i] + nums[j])
    #             pairs = self.twoSum(nums, new_target, j + 1)
    #             for pair in pairs:
    #                 res.append([nums[i], nums[j]] + pair)
    #     return res
    
    def twoSum(self, nums, target, start):
        left, right = start, len(nums) - 1
        res = []
        while left < right:
            summation = nums[left] + nums[right]
            if target == summation:
                res.append([nums[left], nums[right]])
                third, fourth = nums[left], nums[right]
                while left < right and nums[left] == third:
                    left += 1
                while left < right and nums[right] == fourth:
                    right -= 1
            elif target > summation:
                left += 1
            else:
                right -= 1
        return res
    
    def kSum(self, k, nums, start, target):
        if k != 2:
            for i in range(start, len(nums) - k + 1):
                if i > start and nums[i] == nums[i - 1]:
                    continue
                self.quad.append(nums[i])
                self.kSum(k - 1, nums, i + 1, target - nums[i])
                self.quad.pop()
            return
        # base case, two sum ii
        l, r = start, len(nums) - 1
        while l < r:
            if nums[l] + nums[r] < target:
                l += 1
            elif nums[l] + nums[r] > target:
                r -= 1
            else:
                self.res.append(self.quad + [nums[l], nums[r]])
                l += 1
                r -= 1
                while l < r and nums[l] == nums[l - 1]:
                    l += 1