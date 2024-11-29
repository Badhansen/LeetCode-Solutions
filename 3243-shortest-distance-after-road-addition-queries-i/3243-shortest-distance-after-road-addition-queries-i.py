class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        for i in range(1, n):
            graph[i - 1].append(i)
        dist = list(range(n))
        answer = []
        for u, v in queries:
            graph[u].append(v)
            if dist[u] + 1 < dist[v]:
                dist[v] = dist[u] + 1
                queue = deque([v])
                while queue:
                    src = queue.popleft()
                    for dest in graph[src]:
                        if dist[src] + 1 < dist[dest]:
                            dist[dest] = dist[src] + 1
                            queue.append(dest)
            answer.append(dist[n - 1])
        return answer