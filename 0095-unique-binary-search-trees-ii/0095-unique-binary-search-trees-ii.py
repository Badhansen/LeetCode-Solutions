# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def backtrack(self, left: int, right: int) -> List[Optional[TreeNode]]:
        node = []
        if left > right:
            node.append(None)
            return node
        for l in range(left, right + 1):
            left_tree = self.backtrack(left, l - 1)
            right_tree = self.backtrack(l + 1, right)
            for x in left_tree:
                for y in right_tree:
                    curr = TreeNode(l)
                    curr.left = x
                    curr.right = y
                    node.append(curr)
        return node
    
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        return self.backtrack(1, n)