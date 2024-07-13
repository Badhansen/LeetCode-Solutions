# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def dfs(p, q):
            if not p and not q:
                return True
            if not p or not q:
                return False
            left = dfs(p.left, q.left)
            right = dfs(p.right, q.right)
            res = left and right and p.val == q.val
            return res
        return dfs(p, q)