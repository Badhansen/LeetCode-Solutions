class Solution:
    def numDecodings(self, s: str) -> int:
        # dp = [-1] * len(s)
        # def ways(pos):
        #     if pos >= len(s):
        #         return 1
        #     if dp[pos] != -1:
        #         return dp[pos]
        #     take1, take2 = 0, 0
        #     if s[pos] != '0':
        #         take1 = ways(pos + 1)
        #         if pos + 1 < len(s):
        #             num = int(s[pos:pos + 2])
        #             if num <= 26:
        #                 take2 = ways(pos + 2)
        #     dp[pos] = take1 + take2
        #     return dp[pos]
        # return ways(0)
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 0 if s[0] == '0' else 1
        for i in range(2, n + 1):
            if s[i - 1] != '0':
                dp[i] += dp[i - 1]
            num = int(s[i - 2:i])
            if 10 <= num <= 26:
                dp[i] += dp[i - 2]
        return dp[n]
                    