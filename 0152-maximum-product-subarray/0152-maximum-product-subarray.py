class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = float('-inf')
        prod = 1
        for n in nums:
            prod *= n
            res = max(res, prod)
            if prod == 0:
                prod = 1
        prod = 1
        for n in reversed(nums):
            prod *= n
            res = max(res, prod)
            if prod == 0:
                prod = 1
        return res