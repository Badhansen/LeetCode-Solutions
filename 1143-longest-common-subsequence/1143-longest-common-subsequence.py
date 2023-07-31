class Solution:
    def func(self, i: int, j: int, s1: str, s2: str, dp: list()) -> int:
        if i == len(s1):
            return 0
        if j == len(s2):
            return 0
        if dp[i][j] != -1:
            return dp[i][j]
        res = float('-inf')
        if s1[i] == s2[j]:
            res = 1 + self.func(i + 1, j + 1, s1, s2, dp)
        else:
            res = max(res, self.func(i + 1, j, s1, s2, dp))
            res = max(res, self.func(i, j + 1, s1, s2, dp))
        dp[i][j] = res
        return res
    
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[-1] * (len(text2) + 1) for _ in range(len(text1) + 1)]
        return self.func(0, 0, text1, text2, dp)