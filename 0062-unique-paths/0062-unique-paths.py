class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # dp = {}
        # def dfs(r, c):
        #     if r > m or c > n:
        #         return 0
        #     if r == m and c == n:
        #         return 1
        #     if (r, c) in dp:
        #         return dp[(r, c)]
        #     dp[(r, c)] = dfs(r + 1, c) + dfs(r, c + 1)
        #     return dp[(r, c)]
        # return dfs(1, 1)
        dp = [[-1 for _ in range(n)] for _ in range(m)]
        
        def dfs(r, c):
            if r >= m or c >= n:
                return 0
            if r == m - 1 and c == n - 1:
                return 1
            if dp[r][c] != -1:
                return dp[r][c]
            dp[r][c] = dfs(r + 1, c) + dfs(r, c + 1)
            return dp[r][c]
        
        return dfs(0, 0)
        