class Solution:
    def bfs(self, src, dest, graph):
        queue = deque([(src, 0)])
        visited = set([src])
        while queue:
            node, distance = queue.popleft()
            if node == dest:
                return distance
            for nei in graph[node]:
                if nei not in visited:
                    visited.add(nei)
                    queue.append((nei, distance + 1))
        return -1
            
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        answer = []
        for i in range(1, n):
            graph[i - 1].append(i)
        for u, v in queries:
            graph[u].append(v)
            res = self.bfs(0, n - 1, graph)
            answer.append(res)
        return answer