# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = float('-inf')
        
        def dfs(root):
            if not root:
                return 0
            lsum = max(0, dfs(root.left))
            rsum = max(0, dfs(root.right))
            self.res = max(self.res, root.val + lsum + rsum)
            return root.val + max(lsum, rsum)
        
        dfs(root)
        return self.res