class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        roots = []
        deg = [0] * n
        graph = [[] for _ in range(n)]
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
            deg[e[0]] += 1
            deg[e[1]] += 1
        queue = deque()
        for i in range(n):
            if deg[i] == 1:
                queue.append(i)
        while queue:
            size = len(queue)
            roots.clear()
            for i in range(size):
                leaf = queue.popleft()
                roots.append(leaf)
                for node in graph[leaf]:
                    deg[node] -= 1
                    if deg[node] == 1:
                        queue.append(node)
        if n == 1:
            roots.append(0)
        return roots
        