from collections import defaultdict, Counter

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)
        for word in strs:
            counts = [0] * 26
            for c in word:
                counts[ord(c) - ord('a')] += 1
            anagrams[tuple(counts)].append(word)
        return anagrams.values()
'''
Time complexity: O(N * K), where N is the length of strs, and K is the maximum length of a string in strs.
Counting each string is linear in the size of the string, and we count every string.
Space complexity: O(N * K), total information store in anagrams
'''

# class Solution:
#     def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
#         anagrams = defaultdict(list)
#         for word in strs:
#             sword = ''.join(sorted(word))
#             anagrams[sword].append(word)
#         return anagrams.values()

'''
Time complexity: O(N * K log K), where N is the length of strs, and K is the maximum length of a string in strs.
The outer loop has complexity O(N) as we iterate through each string. Then, we sort each string in O(Klog⁡K) time.

Space complexity: O(N * K), total information store in anagrams

'''