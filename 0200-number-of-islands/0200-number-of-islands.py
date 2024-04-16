# @Author: KING-SEN
# Skimming python code

# class Solution:
#     def numIslands(self, grid: List[List[str]]) -> int:
#         row = len(grid); col = len(grid[0])
#         res = 0
        
#         def dfs(r, c):
#             if (not 0 <= r < row) or (not 0 <= c < col) or (grid[r][c] == '0'):
#                 return
#             grid[r][c] = '0'
#             dfs(r - 1, c)
#             dfs(r + 1, c)
#             dfs(r, c - 1)
#             dfs(r, c + 1)
        
#         for r in range(row):
#             for c in range(col):
#                 if grid[r][c] == '1':
#                     res += 1
#                     dfs(r, c)
#         return res

    
# Time: O(row * col)
# Space: O(row * col), because of recursion call stack

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row = len(grid); col = len(grid[0])
        res, visited = 0, set()
        direction = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        for r in range(row):
            for c in range(col):
                if (r, c) not in visited and grid[r][c] == '1':
                    res += 1
                    q = deque()
                    q.append((r, c))
                    while q:
                        a, b = q.popleft()
                        for dr, dc in direction:
                            i, j = a + dr, b + dc
                            if (0 <= i < row) and (0 <= j < col) and ((i, j) not in visited) and grid[i][j] == "1":
                                q.append((i, j))
                                visited.add((i, j))
                
        return res
    
# Time: O(row * col)
# Space: O(min(row * col)), because in worst case where the grid is filled with lands, the size of queue can grow up to min(M, N).
