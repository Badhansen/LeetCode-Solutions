"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def __init__(self):
        self.cache = {}
        
    def dfs(self, node):
        if not node:
            return None
        if node.val in self.cache:
            return self.cache[node.val]
        root = Node(node.val)
        self.cache[node.val] = root
        for child in node.neighbors:
            root.neighbors.append(self.dfs(child))
        return root
    
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        return self.dfs(node)    