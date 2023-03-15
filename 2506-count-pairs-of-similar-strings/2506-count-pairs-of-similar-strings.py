class Solution:
    def similarPairs(self, words: List[str]) -> int:
        result = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if set(words[i]) == set(words[j]):
                    result += 1
        return result
                                        
                                         
            