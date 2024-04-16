# @Author: KING-SEN
# Skimming python code

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row = len(grid); col = len(grid[0])
        res = 0
        
        def dfs(r, c):
            if (not 0 <= r < row) or (not 0 <= c < col) or (grid[r][c] == '0'):
                return
            grid[r][c] = '0'
            dfs(r - 1, c)
            dfs(r + 1, c)
            dfs(r, c - 1)
            dfs(r, c + 1)
        
        for r in range(row):
            for c in range(col):
                if grid[r][c] == '1':
                    res += 1
                    dfs(r, c)
        return res
    
# Time: O(row * col)
# Space: O(row * col), because of recursion call stack