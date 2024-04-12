class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        seen = dict()
        for i, n in enumerate(nums):
            if n in seen and abs(seen[n] - i) <= k:
                return True
            seen[n] = i
        if len(seen) > k:
            seen.pop(nums[i - k]) # Removing the 1th item from (K + 1) length array
        return False

'''
Time Complexity: O(N)
Space Complexity: O(min(N, K))
'''

# class Solution:
#     def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
#         seen = {}
#         for i, n in enumerate(nums):
#             if n in seen and abs(seen[n] - i) <= k:
#                 return True
#             seen[n] = i
#         return False

'''
Time Complexity: O(N)
Space Complexity: O(N)
'''