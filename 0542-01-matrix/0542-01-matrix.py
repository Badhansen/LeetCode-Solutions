class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        def bfs():
            rows, cols = len(mat), len(mat[0])
            res = [[10 ** 9] * cols for i in range(rows)]
            que = deque([])
            visited = set()
            for i in range(rows):
                for j in range(cols):
                    if mat[i][j] == 0:
                        res[i][j] = 0
                        visited.add((i, j))
                        que.append((i, j))
            
            while que:
                a, b = que.popleft()
                for (x, y) in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    nx, ny = a + x, b + y
                    if 0 <= nx < rows and 0 <= ny < cols and mat[nx][ny] == 1 and (nx, ny) not in visited:
                        res[nx][ny] = res[a][b] + 1
                        visited.add((nx, ny))
                        que.append((nx, ny))
            return res
        
        return bfs()