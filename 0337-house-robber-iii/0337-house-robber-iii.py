# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root):
        # Base case return as [with Root, without Root] as pair answer
        if root is None:
            return [0, 0]
        left_result = self.dfs(root.left)
        right_result = self.dfs(root.right)
        with_root = root.val + left_result[1] + right_result[1]
        without_root = max(left_result) + max(right_result)
        return [with_root, without_root]
    
    def rob(self, root: Optional[TreeNode]) -> int:
        answer = self.dfs(root)
        return max(answer)  