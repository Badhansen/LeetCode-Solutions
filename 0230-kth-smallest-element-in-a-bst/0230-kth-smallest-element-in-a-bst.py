# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
#     def __init__(self):
#         # Initialize instance variables
#         self.res = None
#         self.k = 0
    
#     def dfs(self, root):
#         if root is None:
#             return
#         self.dfs(root.left)
#         self.k -= 1
#         if self.k == 0:
#             self.res = root.val
#             return
#         self.dfs(root.right)
        
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # self.res = None
        # self.k = k
        # self.dfs(root)
        # return self.res
        stack = []
        curr = root
        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            k -= 1
            if k == 0:
                return curr.val
            curr = curr.right