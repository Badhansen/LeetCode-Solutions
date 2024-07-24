class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        dp = dict()
        def dfs(s):
            if s in dp:
                return dp[s]
            if s in words:
                return True
            for length in range(1, len(s) + 1):
                prefix = s[:length]
                if prefix in words and dfs(s[length:]):
                    dp[prefix] = True
                    return True
            dp[s] = False
            return dp[s]
        return dfs(s)