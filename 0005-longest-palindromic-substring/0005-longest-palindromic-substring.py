class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * (n + 1) for _ in range(n + 1)]
        # Each character is a palendrome
        for i in range(n):
            dp[i][i] = True
        start, maxLen = 0, 1
        # For length 2
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                start = i
                maxLen = 2
        for l in range(3, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                if dp[i + 1][j - 1] and s[i] == s[j]:
                    dp[i][j] = True
                    start = i
                    maxLen = l
        return s[start:start + maxLen]
        