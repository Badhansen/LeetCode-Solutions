class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.provinces = n

    def find_root(self, node):
        if node == self.parent[node]:
            return node
        self.parent[node] = self.find_root(self.parent[node])  # Path compression
        return self.parent[node]

    def union(self, a, b):
        x = self.find_root(a)
        y = self.find_root(b)
        if x != y:
            self.provinces -= 1
            if self.size[x] < self.size[y]:
                x, y = y, x
            self.parent[y] = x
            self.size[x] += self.size[y]
    
class Solution:
    def findCircleNum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        dsu = UnionFind(n)
        for i in range(n):
            for j in range(n):
                if mat[i][j]:
                    dsu.union(i, j)
        return dsu.provinces            
         
        