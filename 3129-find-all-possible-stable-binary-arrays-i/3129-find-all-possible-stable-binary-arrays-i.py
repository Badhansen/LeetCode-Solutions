class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        MOD = 10 ** 9 + 7
        dp = defaultdict()
        def rec(zero, one, prev):
            if zero < 0 or one < 0:
                return 0
            if zero == 0 and one == 0:
                return 1
            if (zero, one, prev) in dp:
                return dp[(zero, one, prev)]
            res = 0
            for i in range(1, limit + 1):
                if i <= zero and prev != 0:
                    res = (res + rec(zero - i, one, 0)) % MOD
                if i <= one and prev != 1:
                    res = (res + rec(zero, one - i, 1)) % MOD
            dp[(zero, one, prev)] = res
            return res
        return rec(zero, one, 2)