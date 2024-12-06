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
            for x, y in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                dx, dy = r + x, c + y
                dfs(dx, dy)
                
        for r in range(row):
            for c in range(col):
                if grid[r][c] == '1':
                    res += 1
                    dfs(r, c)
        return res

    
# Time: O(row * col)
# Space: O(row * col), because of recursion call stack

# class Solution:
#     def numIslands(self, grid: List[List[str]]) -> int:
#         row = len(grid); col = len(grid[0])
#         direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]
#         res = 0
#         for r in range(row):
#             for c in range(col):
#                 if grid[r][c] == "1":
#                     res += 1
#                     grid[r][c] = "0"
#                     q = deque()
#                     q.append((r, c))
#                     while q:
#                         a, b = q.popleft()
#                         for dr, dc in direction:
#                             i, j = a + dr, b + dc
#                             if (0 <= i < row) and (0 <= j < col) and (grid[i][j] == "1"):
#                                 grid[i][j] = "0"
#                                 q.append((i, j))
#         return res
    
# Time: O(row * col)
# Space: O(min(row * col)), because in worst case where the grid is filled with lands, the size of queue can grow up to min(M, N).
