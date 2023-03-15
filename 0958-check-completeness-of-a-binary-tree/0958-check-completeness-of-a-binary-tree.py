# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        null_node_found = False
        que = deque()
        que.append(root)
        while que:
            node = que.popleft()
            if not node:
                null_node_found = True
            else:
                if null_node_found:
                    return False
                que.append(node.left)
                que.append(node.right)
        return True