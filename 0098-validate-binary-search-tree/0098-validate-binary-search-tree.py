# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def dfs(root, minValue, maxValue):
            if not root:
                return True
            left = dfs(root.left, minValue, root.val)
            right = dfs(root.right, root.val, maxValue)
            res = left and right and minValue < root.val < maxValue
            return res
        return dfs(root, float('-inf'), float('inf'))