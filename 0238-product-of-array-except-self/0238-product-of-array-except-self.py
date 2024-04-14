class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        results = [1] * n
        results[0] = 1
        for i in range(1, n):
            results[i] = results[i - 1] * nums[i - 1]
        right = 1
        for i in range(n - 1, -1, -1):
            results[i] *= right
            right *= nums[i]
        return results
    
'''
Time complexity: O(n)
Space complexity: O(1)
'''
    
# class Solution:
#     def productExceptSelf(self, nums: List[int]) -> List[int]:
#         n = len(nums)
#         left, right = [1] * n, [1] * n
#         left[0], right[n - 1] = nums[0], nums[n - 1]
#         for i in range(1, n):
#             left[i] = left[i - 1] * nums[i]
#         for i in range(n - 2, -1, -1):
#             right[i] = right[i + 1] * nums[i]
#         results = [1] * n
#         for i in range(n):
#             if i > 0:
#                 results[i] *= left[i - 1]
#             if i < n - 1:
#                 results[i] *= right[i + 1]
#         return results
'''
Time complexity: O(n)
Space complexity: O(n)
'''