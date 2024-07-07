class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = defaultdict(lambda: -1)
        def solve(amount):
            if amount < 0:
                return float("inf")
            if amount == 0:
                return 0
            if dp[amount] != -1:
                return dp[amount]
            res = float("inf")
            for coin in coins:
                res = min(res, 1 + solve(amount - coin))
            dp[amount] = res
            return res
        ans = solve(amount)
        return -1 if ans >= float("inf") else ans
            