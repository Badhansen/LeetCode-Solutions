class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        vowels = set('aeiou')
        return sum({words[i][0],words[i][-1]}.issubset(vowels) for i in range(left, right + 1))