from sortedcontainers import SortedList


class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        window = SortedList()
        for i, n in enumerate(nums):
            if i > indexDiff:
                window.remove(nums[i - indexDiff - 1])
            index = window.bisect_left(n - valueDiff)
            if index < len(window) and abs(n - window[index]) <= valueDiff:
                return True
            window.add(n)
        return False
    
'''
N = Lenght of the array
K = Index difference
Time Complexity: O(N * log min(N, K))
Space Complexity: O(min(N, K))
'''