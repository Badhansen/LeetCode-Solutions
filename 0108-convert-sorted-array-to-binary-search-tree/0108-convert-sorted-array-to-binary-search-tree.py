# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# This is the code for Google phone interview
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        queue = deque()
        n = len(nums)
        if n == 0:
            return None
        root = TreeNode(n)
        queue.append(root)
        n -= 1
        level = 1
        while queue and n:
            for i in range(2 ** level):
                if queue:
                    node = queue.popleft()
                else:
                    break
                if n:
                    node.left = TreeNode(n)
                    n -= 1
                    queue.append(node.left)
                if n:
                    node.right = TreeNode(n)
                    n -= 1
                    queue.append(node.right)
                if n == 0:
                    break
        def dfs(root, res):
            if root is None:
                return
            dfs(root.left, res)
            res.append(root)
            dfs(root.right, res)
        res = []
        dfs(root, res)
        for i, num in enumerate(nums):
            res[i].val = num
        return root