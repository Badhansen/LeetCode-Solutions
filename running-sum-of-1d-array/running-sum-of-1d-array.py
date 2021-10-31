# Programming Language Used: C++


class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i in range(len(nums)):
            if i != 0:
                nums[i] += nums[i - 1]
        return nums
    

# Time Complexity: O(N), here N = length of the array
# Space Complexity: O(N)