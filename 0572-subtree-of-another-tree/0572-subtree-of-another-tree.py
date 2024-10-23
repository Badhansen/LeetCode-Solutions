# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, sub_root):
        if root is None and sub_root is None:
            return True
        if root is None or sub_root is None:
            return False
        left, right = self.dfs(root.left, sub_root.left), self.dfs(root.right, sub_root.right)
        return left and right and root.val == sub_root.val
    
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if root is None:
            return False
        if self.dfs(root, subRoot):
            return True
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)