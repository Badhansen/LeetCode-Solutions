class Solution:
    def countSubstrings(self, s: str) -> int:
        count = len(s)
        dp = [[False] * len(s) for i in range(len(s))]
        for i in range(len(s)):
            dp[i][i] = True
        for end in range(len(s)):
            for start in range(end):
                if s[start] == s[end] and (dp[start + 1][end - 1] or end - start == 1):
                    count += 1
                    dp[start][end] = True
        return count