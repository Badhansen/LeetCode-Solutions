# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
    #     if root1 is None:
    #         return root2
    #     if root2 is None:
    #         return root1
    #     root1.val += root2.val
    #     root1.left = self.mergeTrees(root1.left, root2.left)
    #     root1.right = self.mergeTrees(root1.right, root2.right)
    #     return root1
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if root1 is None:
            return root2
        if root2 is None:
            return root1
        stack = [(root1, root2)]
        while stack:
            node1, node2 = stack.pop()
            if node1 is None or node2 is None:
                continue
            node1.val += node2.val
            if node1.left and node2.left:
                stack.append((node1.left, node2.left))
            elif node1.left is None:
                node1.left = node2.left
            if node1.right and node2.right:
                stack.append((node1.right, node2.right))
            elif node1.right is None:
                node1.right = node2.right
        return root1
            
            
            