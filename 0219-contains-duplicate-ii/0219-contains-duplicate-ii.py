class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        seen = {}
        for i, n in enumerate(nums):
            if n in seen and abs(seen[n] - i) <= k:
                return True
            seen[n] = i
        return False

'''
Time Complexity: O(N)
Space Complexity: O(N)
'''