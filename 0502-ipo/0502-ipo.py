class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        pairs = [(profits[i], capital[i]) for i in range(len(profits))] # (profit, capital)
        pairs.sort(key=lambda p:(p[1], -p[0]))
        maxHeap = [] # max profit
        index = 0
        while k:
            while index < len(profits) and pairs[index][1] <= w:
                heapq.heappush(maxHeap, -pairs[index][0])
                index += 1
            if len(maxHeap) == 0:
                break
            w -= heapq.heappop(maxHeap)
            k -= 1
        return w
            
            