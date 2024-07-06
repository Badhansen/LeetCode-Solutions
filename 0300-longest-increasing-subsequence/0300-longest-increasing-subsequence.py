class Solution:
    # def lengthOfLIS(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     dp = [-1] * n
    #     def solve(pos, nums):
    #         if pos == len(nums):
    #             return 1
    #         if dp[pos] != -1:
    #             return dp[pos]
    #         res = 1
    #         for i in range(pos + 1, len(nums)):
    #             if nums[pos] < nums[i]:
    #                 res = max(res, 1 + solve(i, nums))
    #         dp[pos] = res
    #         return res
    #     return max([solve(i, nums) for i in range(n)])
    
    # def lengthOfLIS(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     dp = [1] * n
    #     for i in range(n):
    #         for j in range(i):
    #             if nums[j] < nums[i]:
    #                 dp[i] = max(dp[i], 1 + dp[j])
    #     return max(dp)
    
    def lengthOfLIS(self, nums: List[int]) -> int:
        sub = [nums[0]]
        for num in nums[1:]:
            if num > sub[-1]:
                sub.append(num)
            else:
                # Find the first element in sub that is greater than or equal to num
                i = 0
                while num > sub[i]:
                    i += 1
                sub[i] = num

        return len(sub)
    
'''
Time complexity: O(N^2)
Space complexity: O(N)
'''
    