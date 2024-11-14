# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.path = []
        
    def dfs(self, root, level):
        if root is None:
            return
        if level == len(self.path):
            self.path.append([])
        self.path[level].append(root.val)
        self.dfs(root.left, level + 1)
        self.dfs(root.right, level + 1)
    
    def min_swap(self, nums):
        pairs = [(nums[i], i) for i in range(len(nums))]
        pairs.sort()
        visited = [False] * len(nums)
        res = 0
        for i in range(len(nums)):
            if visited[i] or pairs[i][1] == i:
                continue
            cycle, j = 0, i
            while not visited[j]:
                visited[j] = True
                j = pairs[j][1]
                cycle += 1
            if cycle:
                res += cycle - 1
        return res
    
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        self.dfs(root, 0)
        res = 0
        for i in range(len(self.path)):
            res += self.min_swap(self.path[i])
        return res