class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def dfs(r, c):
            if r < 0 or r >= len(board) or c < 0 or c >= len(board[0]) or board[r][c] != 'O':
                return
            board[r][c] = 'B'
            for x, y in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                dfs(r + x, c + y)
        
        # 1. Mark the 'O' connected to the boundary using DFS
        # Traverse first and last row
        rows, cols = len(board), len(board[0])
        for i in range(cols):
            if board[0][i] == 'O':
                dfs(0, i)
            if board[rows - 1][i] == 'O':
                dfs(rows - 1, i)
        # Traverse first and last column
        for i in range(rows):
            if board[i][0] == 'O':
                dfs(i, 0)
            if board[i][cols - 1] == 'O':
                dfs(i, cols - 1)
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == 'B':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
        
                    