# class Solution:
#     def subsets(self, nums: List[int]) -> List[List[int]]:
#         result = []
#         total = 2 ** len(nums)
#         for i in range(total):
#             res = []
#             for j in range(len(nums)):
#                 if i & (1 << j):
#                     res.append(nums[j])
#             result.append(res)
#         return result

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        def dfs(i, subset):
            if i >= len(nums):
                res.append(subset)
                return
            dfs(i + 1, subset + [nums[i]])
            dfs(i + 1, subset)
        dfs(0, [])
        return res
'''
Time Complexity: O(N * 2^N)  ; because there will be 2^N different subsets, and we have to create a copy of each one, which is O(N).
Space Complexity: O(N)  ; if you don't count the output array, because the size of the function call stack will be O(N). Meaning we have to call the recursive function N times in a row, before it returns.
'''