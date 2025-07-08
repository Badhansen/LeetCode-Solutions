class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        pq = []
        days, left, right = 1, 0, len(events)
        res = 0
        while pq or left < right:
            while left < right and events[left][0] == days:
                heapq.heappush(pq, events[left][1])
                left += 1
            while pq and pq[0] < days:
                heapq.heappop(pq)
            if pq:
                heapq.heappop(pq)
                res += 1
            days += 1
        return res
            