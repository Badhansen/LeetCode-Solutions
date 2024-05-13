class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        res = float("inf")
        pairs = [] # (ratio, quality)
        for i in range(len(quality)):
            pairs.append((wage[i] / quality[i], quality[i]))
        pairs.sort(key=lambda p:p[0])
        
        maxHeap = [] # qualities
        total_qualities = 0
        for rate, q in pairs:
            heapq.heappush(maxHeap, -q)
            total_qualities += q
            
            if len(maxHeap) > k:
                total_qualities += heapq.heappop(maxHeap)
                
            if len(maxHeap) == k:
                res = min(
                    res,
                    total_qualities * rate
                )
        return res