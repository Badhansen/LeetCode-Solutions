class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
#         dp = dict()
        
#         def ways(i, amount):
#             if i == len(coins):
#                 if amount == 0:
#                     return 1
#                 return 0
#             if amount < 0:
#                 return 0
#             if (i, amount) in dp:
#                 return dp[(i, amount)]
#             taken = ways(i, amount - coins[i])
#             not_taken = ways(i + 1, amount)
#             dp[(i, amount)] = taken + not_taken
#             return dp[(i, amount)]
        
#         return ways(0, amount)
        dp = [0] * (amount + 1)
        dp[0] = 1

        for c in coins:
            for a in range(c, amount + 1):
                dp[a] += dp[a-c]
        
        return dp[amount]