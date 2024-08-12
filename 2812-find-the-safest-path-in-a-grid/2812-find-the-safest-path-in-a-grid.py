class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        
        # Calculate safeness factor for each cell using BFS
        queue = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    grid[i][j] = 0
                    queue.append((i, j))
                else:
                    grid[i][j] = -1
        while queue:
            size = len(queue)
            while size:
                r, c = queue.popleft()
                score = grid[r][c]
                for x, y in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                    dx, dy = r + x, c + y
                    if 0 <= dx < n and 0 <= dy < m and grid[dx][dy] == -1:
                        grid[dx][dy] = score + 1
                        queue.append((dx, dy))
                size -= 1
        
        visited = [[False] * m for _ in range(n)]
        pq = [(-grid[0][0], 0, 0)]
        visited[0][0] = True
        while pq:
            safeness, r, c = heapq.heappop(pq)
            safeness *= -1
            
            if r == n - 1 and c == m - 1:
                return safeness
            
            for x, y in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                dx, dy = r + x, c + y
                if 0 <= dx < n and 0 <= dy < m and not visited[dx][dy]:
                    visited[dx][dy] = True
                    s = min(safeness, grid[dx][dy])
                    heapq.heappush(pq, (-s, dx, dy))
                    
        return 0