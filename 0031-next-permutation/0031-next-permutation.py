from itertools import permutations

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        def next_permutation(nums):
            k = len(nums) - 2 # Find the largest index k such that nums[k] < nums[k + 1]
            while k >= 0 and nums[k] >= nums[k + 1]:
                k -= 1
            if k == -1:  # If no such index exists, the permutation is the last permutation
                nums.reverse()
                return False
            # Find the largest index l greater than k such that nums[k] < nums[l]
            l = len(nums) - 1
            while nums[l] <= nums[k]:
                l -= 1
            # Swap nums[k] and nums[l]
            nums[k], nums[l] = nums[l], nums[k]
            # Reverse the sequence from nums[k + 1:]
            nums[k + 1:] = reversed(nums[k + 1:])
            return True
        
        next_permutation(nums)
        
        
'''
The time complexity of the next_permutation function primarily depends on the operations involved in finding the next permutation.

1. Finding k: This step involves traversing the sequence nums once from right to left until we find an index k such that nums[k] < nums[k + 1]. In the worst case, this traversal takes O(n), where n is the length of the sequence nums.
2. Finding l: After finding k, we again traverse the sequence nums from right to left to find the index l. In the worst case, this traversal also takes O(n).
3. Swapping elements: Swapping two elements nums[k] and nums[l] is constant time, O(1).
Reversing the tail: Reversing the tail of the sequence nums from index k + 1 to the end takes O((n - k) / 2) time, which simplifies to O(n - k). In the worst case, this operation also takes O(n).
4. Overall, the time complexity of the next_permutation function is dominated by the operations involved in finding k and l, which are both O(n). Therefore, the total time complexity of the function is O(n).


'''