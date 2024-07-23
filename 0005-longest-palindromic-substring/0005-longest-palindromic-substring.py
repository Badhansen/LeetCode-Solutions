class Solution:
    def expand(self, left, right, s):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1
    
    def longestPalindrome(self, s: str) -> str:
        # n = len(s)
        # dp = [[False] * (n + 1) for _ in range(n + 1)]
        # # Each character is a palendrome
        # for i in range(n):
        #     dp[i][i] = True
        # start, maxLen = 0, 1
        # # For length 2
        # for i in range(n - 1):
        #     if s[i] == s[i + 1]:
        #         dp[i][i + 1] = True
        #         start = i
        #         maxLen = 2
        # for l in range(3, n + 1):
        #     for i in range(n - l + 1):
        #         j = i + l - 1
        #         if dp[i + 1][j - 1] and s[i] == s[j]:
        #             dp[i][j] = True
        #             start = i
        #             maxLen = l
        # return s[start:start + maxLen]
        n = len(s)
        res, start = 1, 0
        for i in range(n):
            len1 = self.expand(i, i, s)
            len2 = self.expand(i, i + 1, s)
            maxLen = max(len1, len2)
            if res < maxLen:
                res = maxLen
                start = i - (maxLen - 1) // 2
        return s[start:start + res]