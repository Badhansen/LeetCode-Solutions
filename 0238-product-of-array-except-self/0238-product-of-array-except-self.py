class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1] * n
        for i in range(1, n):
            res[i] = res[i - 1] * nums[i - 1]
        right = 1
        for i in range(n - 1, -1, -1):
            res[i] *= right
            right *= nums[i]
        return res
'''
Time complexity: O(n)
Space complexity: O(1)
'''

# class Solution:
#     def productExceptSelf(self, nums: List[int]) -> List[int]:
#         n = len(nums)
#         left, right, res = [1] * n, [1] * n, [1] * n
#         for i in range(1, n):
#             left[i] = left[i - 1] * nums[i - 1]
#         for i in range(n - 2, -1, -1):
#             right[i] = right[i + 1] * nums[i + 1]
#         for i in range(n):
#             res[i] = left[i] * right[i]
#         return res
'''
Time complexity: O(n)
Space complexity: O(n)
'''