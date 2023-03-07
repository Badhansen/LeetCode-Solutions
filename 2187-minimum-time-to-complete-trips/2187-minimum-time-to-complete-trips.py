class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        left, right = 1, max(time) * totalTrips
        
        def timeEnough(given_time):
            candoit = 0
            for t in time:
                candoit += given_time // t
            return candoit >= totalTrips
        
        ans = 0
        
        while left <= right:
            mid = (left + right) // 2
            if timeEnough(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
                
        return ans