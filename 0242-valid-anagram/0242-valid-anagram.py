from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        a, b = Counter(s), Counter(t)
        return a == b
    
'''
Time Complexity: O(N + M)
Space Complexity: O(N + M)
'''