class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n + 1)
        dp[n] = True
        for i in range(n - 1, -1, -1):
            for w in wordDict:
                if (i + len(w)) <= n and s[i:i + len(w)] == w:
                    dp[i] = dp[i + len(w)]
                if dp[i]:
                    break
        return dp[0]
        
# class Solution:
#     def wordBreak(self, s: str, wordDict: List[str]) -> bool:
#         words = set(wordDict)
#         dp = dict()
#         def dfs(s):
#             if s in dp:
#                 return dp[s]
#             if s in words:
#                 return True
#             for length in range(1, len(s)):
#                 prefix = s[:length]
#                 if prefix in words and dfs(s[length:]):
#                     dp[prefix] = True
#                     return True
#             dp[s] = False
#             return dp[s]
#         return dfs(s)