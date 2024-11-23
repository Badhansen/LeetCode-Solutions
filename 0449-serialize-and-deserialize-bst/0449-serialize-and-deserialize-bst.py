# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def dfs1(self, root, res):
        if root is None:
            res.append('N')
            return
        res.append(str(root.val))
        self.dfs1(root.left, res)
        self.dfs1(root.right, res)
    
    def dfs2(self, pos, values):
        
        if values[pos[0]] == 'N':
            pos[0] += 1
            return None
        root = TreeNode(int(values[pos[0]]))
        pos[0] += 1
        root.left = self.dfs2(pos, values)
        root.right = self.dfs2(pos, values)
        return root
    
    def serialize(self, root: Optional[TreeNode]) -> str:
        # res = []
        # def dfs(root):
        #     if not root:
        #         res.append("N")
        #         return
        #     res.append(str(root.val))
        #     dfs(root.left)
        #     dfs(root.right)
        # dfs(root)
        # return ",".join(res)
        res = []
        self.dfs1(root, res)
        return ",".join(res)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        # if not data:
        #     return None
        # vals = data.split(",")
        # self.i = 0
        # def dfs():
        #     if vals[self.i] == "N":
        #         self.i += 1
        #         return None
        #     root = TreeNode(int(vals[self.i]))
        #     self.i += 1
        #     root.left = dfs()
        #     root.right = dfs()
        #     return root
        # return dfs()
        if not data:
            return None
        values = data.split(',')
        return self.dfs2([0], values)

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans