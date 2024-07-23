class Solution:
    def countSubstrings(self, s: str) -> int:
        n, count = len(s), len(s)
        dp = [[False] * n for i in range(n)]
        for i in range(n):
            dp[i][i] = True
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                count += 1
        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if dp[i + 1][j - 1] and s[i] == s[j]:
                    count += 1
                    dp[i][j] = True
        return count