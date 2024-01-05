class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        @functools.lru_cache(None)
        def solve(pos):
            if pos == len(nums):
                return 1
            res = 1
            for i in range(pos + 1, len(nums)):
                if nums[pos] < nums[i]:
                    res = max(res, 1 + solve(i))
            return res
        
        return max([solve(i) for i in range(len(nums))])
        