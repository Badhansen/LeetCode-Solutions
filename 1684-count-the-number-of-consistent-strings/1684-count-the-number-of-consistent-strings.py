class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        sets = set(allowed)
        res = 0
        for word in words:
            if set(word).issubset(sets):
                res += 1
        return res