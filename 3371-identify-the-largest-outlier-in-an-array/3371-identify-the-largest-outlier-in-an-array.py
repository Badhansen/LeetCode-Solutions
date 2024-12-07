class Solution:
    def getLargestOutlier(self, nums: List[int]) -> int:
        total = sum(nums)
        freq = Counter(nums)
        res = float('-inf')
        for n in nums:
            outlier = total - n - n
            if freq[outlier] > (outlier == n):
                res = max(res, outlier)
        return res