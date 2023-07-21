class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        dp = {}
        
        def solve(i, prev):
            if i == len(nums):
                return 0, 1
            if (i, prev) in dp:
                return dp[(i, prev)]
            len1, len2, cnt1, cnt2 = 0, 0, 0, 0
            if nums[i] > prev:
                len1, cnt1 = solve(i + 1, nums[i])
                len1 += 1
            len2, cnt2 = solve(i + 1, prev)
            if len1 == len2:
                dp[(i, prev)] = len1, cnt1 + cnt2
            elif len1 > len2:
                dp[(i, prev)] = len1, cnt1
            else:
                dp[(i, prev)] = len2, cnt2
            return dp[(i, prev)]
        
        return solve(0, float('-inf'))[1]
            