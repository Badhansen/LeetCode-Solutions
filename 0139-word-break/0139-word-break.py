class Solution:
    def dfs(self, s, words, dp) -> bool:
        if s in dp:
            return dp[s]
        if s in words:
            return True
        for i in range(1, len(s)):
            prefix = s[:i]
            if prefix in words and self.dfs(s[i:], words, dp):
                dp[prefix] = True
                return True
        dp[s] = False
        return False
            
    
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        dp = {}
        return self.dfs(s, words, dp) 