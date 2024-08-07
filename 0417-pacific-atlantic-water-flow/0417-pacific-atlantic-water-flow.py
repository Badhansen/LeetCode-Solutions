class Solution:
    # def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
    #     rows, cols = len(matrix), len(matrix[0])
    #     pacific = deque()
    #     atlantic = deque()
    #     for i in range(rows):
    #         pacific.append((i, 0))
    #         atlantic.append((i, cols - 1))
    #     for i in range(cols):
    #         pacific.append((0, i))
    #         atlantic.append((rows - 1, i))
    #     def bfs(queue):
    #         reachable = set()
    #         while queue:
    #             (row, col) = queue.popleft()
    #             reachable.add((row, col))
    #             for r, c in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
    #                 nr, nc = r + row, c + col
    #                 if 0 <= nr < rows and 0 <= nc < cols:
    #                     if (nr, nc) in reachable:
    #                         continue
    #                     if matrix[nr][nc] >= matrix[row][col]:
    #                         queue.append((nr, nc))
    #         return reachable
    #     pacificReachable = bfs(pacific)
    #     atlanticReachable = bfs(atlantic)
    #     return list(pacificReachable.intersection(atlanticReachable))
    
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        rows, cols = len(matrix), len(matrix[0])
        pacificReachable = set()
        atlanticReachable = set()
        
        def dfs(r, c, reachable):
            reachable.add((r, c))
            for x, y in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nr, nc = x + r, y + c
                if 0 <= nr < rows and 0 <= nc < cols:
                    if (nr, nc) in reachable:
                        continue 
                    if matrix[nr][nc] >= matrix[r][c]:
                        dfs(nr, nc, reachable)
        
        for i in range(rows):
            dfs(i, 0, pacificReachable)
            dfs(i, cols - 1, atlanticReachable)
        for i in range(cols):
            dfs(0, i, pacificReachable)
            dfs(rows - 1, i, atlanticReachable)
                        
        return list(pacificReachable.intersection(atlanticReachable))