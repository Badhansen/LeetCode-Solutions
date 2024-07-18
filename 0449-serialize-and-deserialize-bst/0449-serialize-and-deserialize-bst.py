# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        res = []
        def dfs(root):
            if not root:
                return None
            res.append(str(root.val))
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        return ",".join(res)
        

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        if not data:
            return None
        ans = [int(d) for d in data.split(",")]
        queue = deque(ans)
        def dfs(queue, left, right):
            if not queue:
                return None
            if not (left <= queue[0] <= right):
                return None
            value = queue.popleft()
            root = TreeNode(value)
            root.left = dfs(queue, left, value)
            root.right = dfs(queue, value, right)
            return root
        return dfs(queue, float('-inf'), float('inf'))

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans