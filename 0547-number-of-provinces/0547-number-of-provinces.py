class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.provinces = n

    def find(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x]) # Path compression
        return self.parent[x]

    def union(self, a, b):
        x = self.find(a)
        y = self.find(b)
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