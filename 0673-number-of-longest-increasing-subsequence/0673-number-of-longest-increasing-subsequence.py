class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        @functools.lru_cache(None)
        def solve(i, prev):
            if i == len(nums):
                return 0, 1
            len1, len2, cnt1, cnt2 = 0, 0, 0, 0
            if nums[i] > prev:
                len1, cnt1 = solve(i + 1, nums[i])
                len1 += 1
            len2, cnt2 = solve(i + 1, prev)
            if len1 == len2:
                return len1, cnt1 + cnt2
            elif len1 > len2:
                return len1, cnt1
            else:
                return len2, cnt2
        
        return solve(0, float('-inf'))[1]
            