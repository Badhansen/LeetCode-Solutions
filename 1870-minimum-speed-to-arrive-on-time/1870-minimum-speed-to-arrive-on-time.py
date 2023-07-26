class Solution:
    def minSpeedOnTime(self, dist: List[int], hours: float) -> int:
        def is_possible(hour):
            time = 0.0
            for i in range(len(dist)):
                if i == len(dist) - 1:
                    time += dist[i] / hour
                else:
                    time += math.ceil(dist[i] / hour)
            return time <= hours
        
        start, end, ans = 1, 10 ** 7, -1
        while start <= end:
            mid = (start + end) // 2
            if is_possible(mid):
                ans = mid
                end = mid - 1
            else:
                start = mid + 1
        return ans
        
        
            