class Solution:
    def isThereAPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        dp = defaultdict(str)
        def dfs(r, c, sum01):
            if r >= m or c >= n:
                return False
            key = str(r) + "|" + str(c) + "|" + str(sum01)
            if key in dp:
                return dp[key]
            sum01 += 1 if grid[r][c] else -1
            if r == m - 1 and c == n - 1:
                return sum01 == 0
            res = False
            for x, y in [[1, 0], [0, 1]]:
                rx, rc = r + x, c + y
                res = res or dfs(rx, rc, sum01)
            dp[key] = res
            return res
        return dfs(0, 0, 0)