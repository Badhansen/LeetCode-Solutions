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
            res = ord(s1[i]) + self.func(i + 1, j + 1, s1, s2, dp)
        else:
            res = max(res, self.func(i + 1, j, s1, s2, dp))
            res = max(res, self.func(i, j + 1, s1, s2, dp))
        dp[i][j] = res
        return res
    
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        dp = [[-1] * (len(s2) + 1) for _ in range(len(s1) + 1)]
        return sum([ord(c) for c in s1]) + sum([ord(c) for c in s2]) - 2 * self.func(0, 0, s1, s2, dp)