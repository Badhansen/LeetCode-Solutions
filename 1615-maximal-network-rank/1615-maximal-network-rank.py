class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        adj = defaultdict(lambda: set())
        for u, v in roads:
            adj[u].add(v)
            adj[v].add(u)
        res = 0
        for u in range(n):
            for v in range(u + 1, n):
                rank = len(adj[u]) + len(adj[v])
                if v in adj[u]:
                    rank -= 1
                res = max(res, rank)
        return res