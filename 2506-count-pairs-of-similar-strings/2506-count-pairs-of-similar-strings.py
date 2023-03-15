class Solution:
    def similarPairs(self, words: List[str]) -> int:
        return sum([set(a) == set(b) for i, a in enumerate(words) for b in words[i + 1:]])
                                        
                                         
            