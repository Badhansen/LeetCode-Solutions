class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        count01 = [[s.count('0'), s.count('1')] for s in strs]
        dp = dict()
        def dfs(pos, m, n):
            if m < 0 or n < 0:
                return -2 ** 31
            if pos == len(strs):
                return 0
            if (pos, m, n) in dp:
                return dp[(pos, m, n)]
            zeros = count01[pos][0]
            ones = count01[pos][1]
            taken = dfs(pos + 1, m - zeros, n - ones) + 1
            not_taken = dfs(pos + 1, m, n)
            dp[(pos, m, n)] = max(taken, not_taken)
            return dp[(pos, m, n)]
        return dfs(0, m, n)