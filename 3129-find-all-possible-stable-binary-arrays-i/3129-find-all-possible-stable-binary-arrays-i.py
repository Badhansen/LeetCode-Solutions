# class Solution:
#     def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
#         dp = defaultdict()
#         MOD = 10 ** 9 + 7
#         def solve(zero, one, prev):
#             if zero < 0 or one < 0:
#                 return 0
#             if zero == 0 and one == 0:
#                 return 1
#             if (zero, one, prev) in dp:
#                 return dp[(zero, one, prev)]
#             res = 0
#             for i in range(1, limit + 1):
#                 if i <= zero and prev != 0:
#                     res = res + solve(zero - i, one, 0)
#                 if i <= one and prev != 1:
#                     res = res + solve(zero, one - i, 1)
#             dp[(zero, one, prev)] = res % MOD
#             return dp[(zero, one, prev)]        
#         return solve(zero, one, 2) % MOD

class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        MOD = 10**9 + 7
        dp = [[[0] * 2 for _ in range(one + 1)] for _ in range(zero + 1)]
        dp[0][0][0] = dp[0][0][1] = 1
        for i in range(zero + 1):
            for j in range(one + 1):
                for l in range(1, limit + 1):
                    if i - l >= 0:
                        dp[i][j][0] = (dp[i][j][0] + dp[i - l][j][1]) % MOD
                    if j - l >= 0:
                        dp[i][j][1] = (dp[i][j][1] + dp[i][j - l][0]) % MOD
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD