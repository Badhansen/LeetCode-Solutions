class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.cities = n

    def find(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x]) # Path compression
        return self.parent[x]

    def union(self, a, b):
        x = self.find(a)
        y = self.find(b)
        if x != y:
            self.cities -= 1
            if self.size[x] < self.size[y]:
                x, y = y, x
            self.parent[y] = x
            self.size[x] += self.size[y]
            
class Solution:
    def minimumCost(self, n: int, connections: List[List[int]]) -> int:
        # Sort edges by cost
        connections.sort(key=lambda edge: edge[2])

        # Kruskal's Algorithm
        dsu = UnionFind(n)
        minimum_cost = 0
        for i, j, cost in connections:
            if dsu.find(i - 1) != dsu.find(j - 1):
                minimum_cost += cost
                dsu.union(i - 1, j - 1)

        return minimum_cost if dsu.cities == 1 else -1 
