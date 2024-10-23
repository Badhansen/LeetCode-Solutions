# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # Recursive
        # res = []
        # def dfs(root):
        #     if root is None:
        #         return
        #     dfs(root.left)
        #     dfs(root.right)
        #     res.append(root.val)
        # dfs(root)
        # return res
        res, stack, visit = [], [root], [False]
        while stack:
            curr, v = stack.pop(), visit.pop()
            if curr:
                if v:
                    res.append(curr.val)
                else:
                    stack.append(curr)
                    visit.append(True)
                    stack.append(curr.right)
                    visit.append(False)
                    stack.append(curr.left)
                    visit.append(False)
        return res