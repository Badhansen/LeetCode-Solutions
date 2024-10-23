# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, p, q):
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        left, right = self.dfs(p.left, q.left), self.dfs(p.right, q.right)
        result = left and right and p.val == q.val
        return result
    
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        return self.dfs(p, q)