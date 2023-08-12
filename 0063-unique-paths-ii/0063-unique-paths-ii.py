class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        rows, cols = len(obstacleGrid), len(obstacleGrid[0])
        dp = {}
        def func(i, j):
            if i >= rows or j >= cols:
                return 0
            if obstacleGrid[i][j] == 1:
                return 0
            if i == rows - 1 and j == cols - 1:
                return 1
            if (i, j) in dp:
                return dp[(i, j)]
            right = func(i, j + 1)
            down = func(i + 1, j)
            dp[(i, j)] = right + down
            return dp[(i, j)]
        return func(0, 0)