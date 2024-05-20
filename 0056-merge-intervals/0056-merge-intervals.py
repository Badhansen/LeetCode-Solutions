class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda p:p[0])
        res = []
        for start, end in intervals:
            if not res or res[-1][1] < start:
                res.append([start, end])
            else:
                res[-1][1] = max(res[-1][1], end)
        return res
'''
Time Complexity: O(N log N), where N is the length of the array
Space Complexity: O(N), we have to store the result for answer, so if every interval is unique then for the worst part it will be O(N)
'''
    