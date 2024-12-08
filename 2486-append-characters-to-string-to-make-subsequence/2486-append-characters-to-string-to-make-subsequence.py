class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        start = 0
        for c in s:
            if start < len(t) and c == t[start]:
                start += 1
        return len(t) - start