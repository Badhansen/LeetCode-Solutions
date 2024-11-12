class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x:x[1])
        heap = []
        days = 0
        for dur, lastday in courses:
            days += dur
            heapq.heappush(heap, -dur)
            if days > lastday:
                days += heapq.heappop(heap)
        return len(heap)