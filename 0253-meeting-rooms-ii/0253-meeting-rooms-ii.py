class Solution:
    # def minMeetingRooms(self, intervals: List[List[int]]) -> int:
    #     intervals.sort(key=lambda x : (x[0], x[1]))
    #     n = len(intervals)
    #     res = [intervals[0][1]]
    #     ans = 1
    #     for i in range(1, n):
    #         while res and res[0] <= intervals[i][0]:
    #             heapq.heappop(res)
    #         heapq.heappush(res, intervals[i][1])
    #         ans = max(ans, len(res))
    #     return ans
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        splitedIntervals = []
        for start, end in intervals:
            splitedIntervals.append((start, 1))
            splitedIntervals.append((end, -1))
        splitedIntervals.sort()
        ans = 0
        count = 0
        for start, meeting in splitedIntervals:
            count += meeting
            ans = max(ans, count)
        return ans