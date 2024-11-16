# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# class Solution:
#     def goodNodes(self, root: TreeNode) -> int:
#         def dfs(root, maxValue):
#             if not root:
#                 return 0
#             res = 1 if root.val >= maxValue else 0
#             maxValue = max(maxValue, root.val)
#             res += dfs(root.left, maxValue)
#             res += dfs(root.right, maxValue)
#             return res
#         return dfs(root, root.val)

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        res = 0
        q = deque()
        q.append((root,-float('inf')))
        while q:
            node,maxval = q.popleft()
            if node.val >= maxval:  
                res += 1
            if node.left:    
                q.append((node.left,max(maxval,node.val)))
            if node.right:
                q.append((node.right,max(maxval,node.val)))
        return res
