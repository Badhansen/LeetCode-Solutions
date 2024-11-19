class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        line = [0] * (n + 1)
        for l, r in queries:
            line[l] += 1
            line[r + 1] -= 1
        for i in range(1, n + 1):
            line[i] += line[i - 1]
        for i in range(n):
            if nums[i] > line[i]:
                return False
        return True