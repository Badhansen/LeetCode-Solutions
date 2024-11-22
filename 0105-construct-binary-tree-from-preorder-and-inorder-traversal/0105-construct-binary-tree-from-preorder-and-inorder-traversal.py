class Solution:
    def dfs(self, left, right, pos, preorder, maps):
        if left > right:
            return None
        value = preorder[pos[0]]
        pos[0] += 1
        root = TreeNode(value)
        mid = maps[value]
        root.left = self.dfs(left, mid - 1, pos, preorder, maps)
        root.right = self.dfs(mid + 1, right, pos, preorder, maps)
        return root
        
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        maps = {value:i for i, value in enumerate(inorder)}
        return self.dfs(0, len(preorder) - 1, [0], preorder, maps)
        # if not preorder or not inorder:
        #     return None
        # root = TreeNode(preorder[0])
        # mid = inorder.index(preorder[0])
        # root.left = self.buildTree(preorder[1:mid + 1], inorder[:mid])
        # root.right = self.buildTree(preorder[mid + 1:], inorder[mid + 1:])
        # return root


# # Definition for a binary tree node.
# # class TreeNode:
# #     def __init__(self, val=0, left=None, right=None):
# #         self.val = val
# #         self.left = left
# #         self.right = right
# class Solution:
#     def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
#         def build(left, right, preIndex):
#             if left > right:
#                 return None, preIndex
#             val = preorder[preIndex]
#             root = TreeNode(val)
#             preIndex += 1
#             index = inorder.index(val)
#             root.left, preIndex = build(left, index - 1, preIndex)
#             root.right, preIndex = build(index + 1, right, preIndex)
#             return root, preIndex
#         root, p = build(0, len(inorder) - 1, 0)
#         return root

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
            
            