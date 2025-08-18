class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        if not intervals:
            return True
        intervals.sort()
        end = intervals[0][1]
        for s, e in intervals[1:]:
            if s < end:
                return False
            end = e
        return True