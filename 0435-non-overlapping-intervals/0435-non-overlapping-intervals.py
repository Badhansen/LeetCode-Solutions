class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])
        res, last = 1, intervals[0]
        for i in range(1, len(intervals)):
            if intervals[i][0] >= last[1]:
                res += 1
                last = intervals[i]
        return len(intervals) - res