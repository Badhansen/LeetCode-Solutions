class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hash_set = set()
        for n in nums:
            if n in hash_set:
                return True
            hash_set.add(n)
        return False

'''
Here N = Number of elements
Time Complexity: O(N)
Space Complexity: O(N)
'''
