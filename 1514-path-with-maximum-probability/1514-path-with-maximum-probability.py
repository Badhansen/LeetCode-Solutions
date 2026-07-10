class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        graph = defaultdict(list)
        p = [0.0] * n
        for idx, (u, v) in enumerate(edges):
            graph[u].append((v, idx))
            graph[v].append((u, idx))
        p[start_node] = 1.0
        pq = [(-p[start_node], start_node)]
        while pq:
            prob, curr = heapq.heappop(pq)
            prob = -prob
            if curr == end_node:
                return prob
            for neighbor, index in graph[curr]:
                if  prob * succProb[index] > p[neighbor]:
                    p[neighbor] = prob * succProb[index]
                    heapq.heappush(pq, (-1 * p[neighbor], neighbor))
        return 0.0