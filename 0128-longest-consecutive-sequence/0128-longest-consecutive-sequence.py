class Solution:
    # def longestConsecutive(self, nums: List[int]) -> int:
    #     seen = defaultdict(int)
    #     for i, n in enumerate(nums):
    #         seen[n] = i
    #     res = 0
    #     for n in nums:
    #         if (n - 1) not in seen:
    #             curr = n
    #             seq = 1
    #             while (curr + 1) in seen:
    #                 curr += 1
    #                 seq += 1
    #             res = max(res, seq)
    #     return res
    def longestConsecutive(self, nums):
        nums = set(nums)
        best = 0
        for x in nums:
            if x - 1 not in nums:
                y = x + 1
                while y in nums:
                    y += 1
                best = max(best, y - x)
        return best