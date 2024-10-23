# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
	    self.diameter = 0  # stores the maximum diameter calculated
        
    def depth(self, root):
        if root is None:
            return 0
        left, right = self.depth(root.left), self.depth(root.right)
        self.diameter = max(self.diameter, left + right) 
        return max(left, right) + 1
    
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.depth(root)
        return self.diameter
        