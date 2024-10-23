# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.path = []
        
    def dfs(self, root):
        if root is None:
            return
        self.dfs(root.left)
        self.path.append(root.val)
        self.dfs(root.right)
        
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.dfs(root)
        return self.path