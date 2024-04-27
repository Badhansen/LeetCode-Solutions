# class Solution:
#     def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
#         roots = []
#         deg = [0] * n
#         graph = [[] for _ in range(n)]
#         for e in edges:
#             graph[e[0]].append(e[1])
#             graph[e[1]].append(e[0])
#             deg[e[0]] += 1
#             deg[e[1]] += 1
#         queue = deque()
#         for i in range(n):
#             if deg[i] == 1:
#                 queue.append(i)
#         while queue:
#             size = len(queue)
#             roots.clear()
#             for i in range(size):
#                 leaf = queue.popleft()
#                 roots.append(leaf)
#                 for node in graph[leaf]:
#                     deg[node] -= 1
#                     if deg[node] == 1:
#                         queue.append(node)
#         if n == 1:
#             roots.append(0)
#         return roots

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(n)]
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
            
        hs = [0] * n
        ht = [0] * n
        def dfs(u, p):
            for v in graph[u]:
                if v == p:
                    continue
                dfs(v, u)
                hs[u] = max(hs[u], 1 + hs[v])
        def dfs2(u, p, pd):
            ht[u] = max(pd, hs[u])
            w = []
            w.append([pd, p])
            for v in graph[u]:
                if v != p:
                    w.append([hs[v] + 1, v])
            w.sort(reverse=True)
            for v in graph[u]:
                if v != p:
                    dfs2(v, u, w[1][0] + 1 if w[0][1] == v else w[0][0] + 1)
        dfs(0, -1)
        dfs2(0, -1, 0)
        mh = min(ht)
        roots = [i for i in range(n) if ht[i] == mh]
        return roots