class Solution:
    def partitionString(self, s: str) -> int:
        seen = [-1] * 26
        res, last_starting = 1, 0
        for i, c in enumerate(s):
            if seen[ord(c) - ord('a')] >= last_starting:
                print(i)
                res += 1
                last_starting = i
            seen[ord(c) - ord('a')] = i
        return res