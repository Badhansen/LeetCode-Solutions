# class Solution:
#     def climbStairs(self, n: int) -> int:
#         dp = dict()
        
#         def ways(i):
#             if i == n:
#                 return 1
#             if i > n:
#                 return 0
#             if i in dp:
#                 return dp[i]
#             dp[i] = ways(i + 1) + ways(i + 2)
#             return dp[i]
        
#         return ways(0)
#     def climbStairs(self, n: int) -> int:
#         dp = [0] * (n + 1)
#         dp[0] = dp[1] = 1
#         for i in range(2, n + 1):
#             dp[i] = dp[i - 1] + dp[i - 2]
#         return dp[n]
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 3:
            return n
        n1, n2 = 2, 3

        for i in range(4, n + 1):
            temp = n1 + n2
            n1 = n2
            n2 = temp
        return n2

    
    