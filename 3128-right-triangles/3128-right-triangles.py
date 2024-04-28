class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        rsum = [0] * row
        csum = [0] * col
        for r in range(row):
            for c in range(col):
                rsum[r] += grid[r][c]
                csum[c] += grid[r][c]
        res = 0
        for r in range(row):
            for c in range(col):
                if grid[r][c]:
                    res += (rsum[r] - 1) * (csum[c] - 1)
        return res
        