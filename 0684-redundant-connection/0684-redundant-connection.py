class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x]) # Path compression
        return self.parent[x]

    def union(self, a, b):
        x = self.find(a)
        y = self.find(b)
        if x != y:
            if self.size[x] < self.size[y]:
                x, y = y, x
            self.parent[y] = x
            self.size[x] += self.size[y]
        else:
            return [a, b]
        return [-1, -1]
    
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        dsu = UnionFind(n + 1)
        for u, v in edges:
            edge = dsu.union(u, v)
            if edge[0] != -1:
                return edge
        return [0, 0]
    
"""
Time Complexity: O(Nα(N))≈O(N), where 
N is the number of vertices (and also the number of edges) in the graph, and 
α is the Inverse-Ackermann function ans complexity approximately O(1)..
Space Complexity: O(N)
"""