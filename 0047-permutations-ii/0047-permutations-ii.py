class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        
        def dfs(index):
            if index == len(nums):
                res.append(nums[:])
                return
            lookup = set()
            for i in range(index, len(nums)):
                if nums[i] not in lookup:
                    nums[i], nums[index] = nums[index], nums[i]
                    dfs(index + 1)
                    nums[i], nums[index] = nums[index], nums[i]
                    lookup.add(nums[i])
                
        dfs(0)
        return res
    
'''
The time complexity of the provided code is O(n*n!), where n is the number of elements in the input list nums.

Let's break down the time complexity:

1. Sorting: Sorting the input list nums takes O(nlogn) time using Python's built-in sorting algorithm, where n is the length of the list.
2. Depth-First Search (DFS):
The DFS function is called recursively to generate all permutations of the elements in nums.
At each level of recursion, there are (n−index) choices for the element to place at that position.
There are n! permutations of n elements, so there are n! leaf nodes in the recursion tree.
At each level of the recursion tree, we have O(n) work for the loop and swapping operations.
Therefore, the total work done by the DFS function is O(n*n!).
3. Combining the Factors:
Since the sorting operation dominates the time complexity, the overall time complexity is O(nlogn)+O(n⋅n!).
In big O notation, the term O(n⋅n!) dominates for large values of n, so we can simplify the overall time complexity to O(n⋅n!).
Therefore, the time complexity of the provided code is O(n⋅n!).
'''