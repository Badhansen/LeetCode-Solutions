class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        count_s, count_t = defaultdict(int), defaultdict(int)
        for i in range(len(s)):
            count_s[s[i]] = count_s[s[i]] + 1
            count_t[t[i]] = count_t[t[i]] + 1
        return count_s == count_t
    
'''
Time Complexity: O(N + M)
Space Complexity: O(N + M)
'''

# from collections import Counter

# class Solution:
#     def isAnagram(self, s: str, t: str) -> bool:
#         a, b = Counter(s), Counter(t)
#         return a == b
    
# '''
# Time Complexity: O(N + M)
# Space Complexity: O(N + M)
# '''