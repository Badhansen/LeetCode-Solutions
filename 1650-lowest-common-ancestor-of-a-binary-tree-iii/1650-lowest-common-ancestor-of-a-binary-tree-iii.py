"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        seen = defaultdict(bool)
        curr = p
        while curr:
            seen[curr.val] = True
            curr = curr.parent
        curr = q
        while curr:
            if curr.val in seen:
                return curr
            curr = curr.parent
        return None
        
            