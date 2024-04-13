class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = defaultdict(lambda: -1)
        for i, n in enumerate(nums):
            complement = target - n
            if complement in seen: 
                return [i, seen[complement]]
            seen[n] = i
        return [0, 0]
    
'''
Time complexity: O(N)
Space complexity: O(N)
'''
            