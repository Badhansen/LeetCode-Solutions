class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        dp = [startFuel]+[0]*len(stations)
        for i, (loc,cap) in enumerate(stations):
            for j in range(i,-1,-1):
                if dp[j] >= loc:
                    dp[j + 1] = max(dp[j+1],dp[j]+cap)
        for i,val in enumerate(dp):
            if val >= target:
                return i
        return -1