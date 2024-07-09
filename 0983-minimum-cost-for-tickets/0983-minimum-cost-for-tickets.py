class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [0] * 366
        for d in days:
            dp[d] = costs[0]
        for i in range(1, 366):
            if dp[i] == 0:
                dp[i] = dp[i - 1]
            else:
                dp[i] = costs[0] + dp[i - 1] 
                j = max(0, i - 7)
                dp[i] = min(dp[i], dp[j] + costs[1])
                j = max(0, i - 30)
                dp[i] = min(dp[i], dp[j] + costs[2])
        return dp[365]
            