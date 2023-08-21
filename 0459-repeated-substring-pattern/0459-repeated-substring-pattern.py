class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        text = s + s
        if s in text[1:-1]:
            return True
        return False