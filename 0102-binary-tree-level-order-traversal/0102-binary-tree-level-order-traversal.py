# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # res = []
        # def dfs(root, level):
        #     if not root:
        #         return
        #     if level == len(res):
        #         res.append([])
        #     res[level].append(root.val)
        #     dfs(root.left, level + 1)
        #     dfs(root.right, level + 1)
        # dfs(root, 0)
        # return res
        result = []
        queue = deque()
        if root:
            queue.append(root)
        while queue:
            res = []
            for i in range(len(queue)):
                node = queue.popleft()
                res.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            result.append(res)
        return result