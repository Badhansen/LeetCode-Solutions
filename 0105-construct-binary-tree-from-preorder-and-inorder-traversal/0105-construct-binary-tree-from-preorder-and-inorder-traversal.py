# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def build(left, right, preIndex):
            if left > right:
                return None, preIndex
            val = preorder[preIndex]
            root = TreeNode(val)
            preIndex += 1
            index = inorder.index(val)
            root.left, preIndex = build(left, index - 1, preIndex)
            root.right, preIndex = build(index + 1, right, preIndex)
            return root, preIndex
        root, p = build(0, len(inorder) - 1, 0)
        return root

# # Definition for a binary tree node.
# # class TreeNode:
# #     def __init__(self, val=0, left=None, right=None):
# #         self.val = val
# #         self.left = left
# #         self.right = right
# class Solution:
#     def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
#         preIndex = 0
#         def build(left, right):
#             nonlocal preIndex
#             if left > right:
#                 return None
#             val = preorder[preIndex]
#             root = TreeNode(val)
#             preIndex += 1
#             index = inorder.index(val)
#             root.left = build(left, index - 1)
#             root.right = build(index + 1, right)
#             return root
#         root = build(0, len(inorder) - 1)
#         return root
            
            