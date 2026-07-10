class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = defaultdict(list)
        for u, v, t in times:
            graph[u].append((v, t))
        dist = [float('inf')] * (n + 1)
        dist[0] = dist[k] = 0
        pq = [(0, k)]
        while pq:
            time, src = heapq.heappop(pq)
            if time > dist[src]:
                continue
            for dest, time in graph[src]:
                if dist[dest] > dist[src] + time:
                    dist[dest] = dist[src] + time
                    pq.append((dist[dest], dest))
        res = max(dist)
        return res if res != float('inf') else -1 

