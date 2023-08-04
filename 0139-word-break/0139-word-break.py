class Solution:
    def backtrack(self, idx: int, dp: List[bool], s: str, words: Set[str]) -> bool:
        if idx == len(s):
            return True
        if idx in dp:
            return dp[idx]
        for i in range(idx + 1, len(s) + 1):
            if s[idx:i] in words and self.backtrack(i, dp, s, words):
                dp[idx] = True
                return True
        dp[idx] = False
        return False
    
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        dp = {}
        return self.backtrack(0, dp, s, words) 