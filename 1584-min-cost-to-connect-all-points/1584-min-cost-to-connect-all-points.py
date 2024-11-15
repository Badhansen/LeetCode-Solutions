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

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        edges: List[Tuple[int, int, int]] = []  # (weight, point1, point2)
        for i in range(n):
            for j in range(i + 1, n):
                weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                edges.append((weight, i, j))

        # Sort edges by weight
        edges.sort(key=lambda edge: edge[0])

        # Kruskal's Algorithm
        dsu = UnionFind(n)
        minimum_cost = 0
        for cost, i, j in edges:
            if dsu.find(i) != dsu.find(j):
                minimum_cost += cost
                dsu.union(i, j)

        return minimum_cost
        