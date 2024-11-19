class Solution:
    def isZeroArrayPossibleWithK(self, nums: List[int], queries: List[List[int]], k: int) -> bool:
        n = len(nums)
        line = [0] * (n + 1)
        for i in range(k):
            l, r, val = queries[i]
            line[l] += val
            line[r + 1] -= val
        for i in range(1, n + 1):
            line[i] += line[i - 1]
        for i in range(n):
            if nums[i] > line[i]:
                return False
        return True
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        left, right, ans = 0, len(queries), -1
        while left <= right:
            k = (left + right) // 2
            if self.isZeroArrayPossibleWithK(nums, queries, k):
                ans = k
                right = k - 1
            else:
                left = k + 1
        return ans