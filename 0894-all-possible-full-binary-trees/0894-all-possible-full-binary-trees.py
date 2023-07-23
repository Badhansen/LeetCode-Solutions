# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        dp = {}
        def backtrack(n):
            if n % 2 == 0:
                return []
            if n == 1:
                return [TreeNode()]
            if n in dp:
                return dp[n]
            res = []
            for i in range(1, n, 2):
                left = backtrack(i)
                right = backtrack(n - i - 1)
                
                for l in left:
                    for r in right:
                        root = TreeNode(0, l, r)
                        res.append(root)
            dp[n] = res
            return res
        return backtrack(n)