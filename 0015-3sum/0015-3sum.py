class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        for i, n in enumerate(nums):
            if n > 0:
                break
            if i > 0 and n == nums[i - 1]:
                continue
            
            l, r = i + 1, len(nums) - 1
            while l < r:
                sum = n + nums[l] + nums[r]
                if sum > 0:
                    r -= 1
                elif sum < 0:
                    l += 1
                else:
                    result.append([n, nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return result
    
'''
Time complexity: O(n^2)
Space Complexity: In this example O(1), as the sort method sorts the list in place, meaning it doesn't create a new list. It modifies the original list.
But it may be from O(log⁡n) to O(n), depending on the implementation of the sorting algorithm. For the purpose of complexity analysis, we ignore the memory required for the output.
'''