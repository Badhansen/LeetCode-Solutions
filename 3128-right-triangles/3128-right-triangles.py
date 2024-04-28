class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        rc = [[0] * (col + 1) for _ in range(row + 1)]
        cc = [[0] * (col + 1) for _ in range(row + 1)]
        for r in range(row):
            for c in range(col):
                if grid[r][c]:
                    rc[r + 1][c + 1] = 1
            for c in range(0, col):
                rc[r + 1][c + 1] += rc[r + 1][c]
        for c in range(col):
            for r in range(row):
                if grid[r][c]:
                    cc[r + 1][c + 1] = 1
            for r in range(0, row):
                cc[r + 1][c + 1] += cc[r][c + 1]
        # print(rc)
        # print(cc)
        result = 0
        for r in range(row):
            for c in range(col):
                # There are 4 possible trianges
                if grid[r][c]:
                    if rc[r + 1][col] - rc[r + 1][c] >= 2 and cc[r + 1][c + 1] >= 2:
                        up = cc[r + 1][c + 1] - 1
                        right = rc[r + 1][col] - rc[r + 1][c] - 1
                        # print("up:", up, "right:", right)
                        result += (up * right)
                    if rc[r + 1][col] - rc[r + 1][c] >= 2 and cc[row][c + 1] - cc[r][c + 1] >= 2:
                        right = rc[r + 1][col] - rc[r + 1][c] - 1
                        down = cc[row][c + 1] - cc[r][c + 1] - 1
                        # print("down:", down, "right:", right)
                        result += (right * down)
                    if rc[r + 1][c + 1] >= 2 and cc[row][c + 1] - cc[r][c + 1] >= 2:
                        left = rc[r + 1][c + 1] - 1
                        down = cc[row][c + 1] - cc[r][c + 1] - 1
                        # print("down:", down, "left:", left)
                        result += (left * down)
                    if rc[r + 1][c + 1] >= 2 and cc[r + 1][c + 1] >= 2:
                        up = cc[r + 1][c + 1] - 1
                        left = rc[r + 1][c + 1] - 1
                        # print("up:", up, "left:", left)
                        result += (up * left)
        return result