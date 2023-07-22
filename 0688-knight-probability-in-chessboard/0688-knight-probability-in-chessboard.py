class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        directions = [(-1,-2),(1,-2),(2,-1),(2,1),(-1,2),(1,2),(-2,-1),(-2,1)]
        queue = defaultdict(int)
        queue[row, column] = 1.0
        p = 1
        for _ in range(k):
            p = 0
            _next = defaultdict(int)
            for (r, c), rcp in queue.items():
                for dr, dc in directions:
                    if 0 <= (nr := r + dr) < n and 0 <= (nc := c + dc) < n:
                        _next[nr, nc] += rcp / 8
                        p += rcp / 8
            queue = _next
        return p