class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(r, c, pos):
            if board[r][c] != word[pos]:
                return False
            if pos == len(word) - 1:
                return True
            board[r][c] = '$'
            res = False
            for i, j in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                nr = i + r
                nc = j + c
                if 0 <= nr < len(board) and 0 <= nc < len(board[0]) and not res:
                    res |= dfs(nr, nc, pos + 1)
                if res:
                    return res
            board[r][c] = word[pos]
            return res
        for r in range(len(board)):
            for c in range(len(board[0])):
                if dfs(r, c, 0):
                    return True
        return False
                