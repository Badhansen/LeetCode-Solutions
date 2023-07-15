class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        n = len(events)
        high = [0] * n
        for i in range(n):
            high[i] = events[i][1]
        high.sort()
        events.sort(key=lambda x: x[1])
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                l = bisect_left(high, events[i - 1][0])
                dp[i][j] = max(dp[i - 1][j], events[i - 1][2] + dp[l][j - 1])
        return dp[n][k]