class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        answer, vowels = 0, ['a', 'e', 'i', 'o', 'u']
        for i in range(left, right + 1):
            if words[i][0] in vowels and words[i][-1] in vowels:
                answer += 1
        return answer