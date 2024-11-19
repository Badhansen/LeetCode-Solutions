class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        def dfs(r, c, marked):
            if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or grid[r][c] != marked:
                return
            grid[r][c] = 2
            for x, y in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                dfs(r + x, c + y, marked)
        
        # 1. Mark the 1 connected to the boundary using DFS
        # Traverse first and last row
        rows, cols = len(grid), len(grid[0])
        marked = 0
        for i in range(cols):
            if grid[0][i] == marked:
                dfs(0, i, marked)
            if grid[rows - 1][i] == marked:
                dfs(rows - 1, i, marked)
        # Traverse first and last column
        for i in range(rows):
            if grid[i][0] == marked:
                dfs(i, 0, marked)
            if grid[i][cols - 1] == marked:
                dfs(i, cols - 1, marked)
        res = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == marked:
                    res += 1
                    dfs(i, j, marked)
        return res
        
                    