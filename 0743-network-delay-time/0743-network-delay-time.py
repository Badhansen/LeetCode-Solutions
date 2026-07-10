class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = defaultdict(list)
        for u, v, weight in times:
            graph[u].append((v, weight))

        dist = [float("inf")] * (n + 1)
        dist[k] = 0
        pq = [(0, k)]
        while pq:
            curr_time, src = heapq.heappop(pq)
            if curr_time > dist[src]:
                continue
            for dest, weight in graph[src]:
                new_time = curr_time + weight
                if new_time < dist[dest]:
                    dist[dest] = new_time
                    heapq.heappush(pq, (new_time, dest))
        res = max(dist[1:])
        return res if res != float("inf") else -1 

