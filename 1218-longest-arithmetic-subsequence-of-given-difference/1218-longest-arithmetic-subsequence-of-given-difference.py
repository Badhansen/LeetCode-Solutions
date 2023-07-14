class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        n = len(arr)
        dp = defaultdict(lambda: 0)
        res = 1
        for num in arr:
            dp[num] = 1 + dp[num - difference]
            res = max(res, dp[num])
        return res