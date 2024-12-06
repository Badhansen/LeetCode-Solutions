class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter = Counter(tasks)
        pq = [-val for val in counter.values()]
        heapq.heapify(pq)
        q = deque()
        time = 0
        while q or pq:
            time += 1
            if pq:
                count = 1 + heapq.heappop(pq)
                if count:
                    q.append((count, time + n))
            if q and q[0][1] == time:
                heapq.heappush(pq, q.popleft()[0])
        return time              
    
"""
Time: O(N * M) -> length of the string and the interval length
Space: O(26) ~ O(1)
"""