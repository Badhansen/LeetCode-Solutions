"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""
"""
The idea is fairly simple (and the same as finding the convergence point of 2 linked lists). We keep two pointers, p1 and p2. Originally, these pointers point to q and p, respectively. Then we follow their parent pointers until they point to the same node. When either of the pointers points to root, we set it to the other original starting node. For example, when p1 points to root (i.e p1.parent is None), assign q to p1.
"""
class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        # seen = defaultdict(bool)
        # curr = p
        # while curr:
        #     seen[curr.val] = True
        #     curr = curr.parent
        # curr = q
        # while curr:
        #     if curr.val in seen:
        #         return curr
        #     curr = curr.parent
        # return None
        root1, root2 = p, q
        while root1 != root2:
            root1 = root1.parent if root1.parent else q
            root2 = root2.parent if root2.parent else p
        return root1
        
            