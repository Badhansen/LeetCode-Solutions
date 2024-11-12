class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find_root(self, node):
        if node == self.parent[node]:
            return node
        self.parent[node] = self.find_root(self.parent[node])  # Path compression
        return self.parent[node]

    def union(self, a, b):
        x = self.find_root(a)
        y = self.find_root(b)
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