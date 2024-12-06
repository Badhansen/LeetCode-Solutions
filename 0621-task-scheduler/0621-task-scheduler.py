class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter = Counter(tasks)
        heap = []
        queue = deque()
        for key, val in counter.items():
            heapq.heappush(heap, -val)
        time = 0
        while queue or heap:
            time += 1
            if heap:
                if abs(heap[0]) - 1 > 0:
                    queue.append((abs(heap[0]) - 1, time + n))
                heapq.heappop(heap)
            if queue and queue[0][1] == time:
                heapq.heappush(heap, -1 * queue.popleft()[0])
        return time              