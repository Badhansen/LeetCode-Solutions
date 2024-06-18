class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = defaultdict(int)
        for i, n in enumerate(nums):
            seen[n] = i
        res = 0
        for n in nums:
            if (n - 1) not in seen:
                curr = n
                seq = 1
                while (curr + 1) in seen:
                    curr += 1
                    seq += 1
                res = max(res, seq)
        return res