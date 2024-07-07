class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic = [-1] * 256
        maxLen, start = 0, -1
        for i, c in enumerate(s):
            if dic[ord(c)] > start:
                start = dic[ord(c)]
            dic[ord(c)] = i
            maxLen = max(maxLen, i - start)
        return maxLen