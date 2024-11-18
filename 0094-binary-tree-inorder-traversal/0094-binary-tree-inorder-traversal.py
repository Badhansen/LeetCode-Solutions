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
# class Solution:
#     def inorderTraversal(self, root):
#         res = []
#         self.helper(root, res)
#         return res

#     def helper(self, root, res):
#         if root is not None:
#             self.helper(root.left, res)
#             res.append(root.val)
#             self.helper(root.right, res)

# class Solution:
#     def inorderTraversal(self, root):
#         result = []
#         stack = []
#         curr = root
#         while curr or stack:
#             while curr:
#                 stack.append(curr)
#                 curr = curr.left
#             curr = stack.pop()
#             result.append(curr.val)
#             curr = curr.right
#         return result
        