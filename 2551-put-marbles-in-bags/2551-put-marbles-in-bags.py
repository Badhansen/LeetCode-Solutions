from heapq import heappop, heappush, heapify

class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        n = len(weights)
        max_heap = []
        min_heap = []
        for i in range(n - 1):
            heappush(max_heap, weights[i] + weights[i + 1])
            heappush(min_heap, -1 * (weights[i] + weights[i + 1]))
            if len(max_heap) >= k:
                heappop(max_heap)
                heappop(min_heap)
        return sum(max_heap) + sum(min_heap)