# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res = []
        
    def dfs(self, root, level):
        if root is None:
            return
        if level == len(self.res):
            self.res.append(root.val)
        self.dfs(root.right, level + 1)
        self.dfs(root.left, level + 1)
        
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.dfs(root, 0)
        return self.res