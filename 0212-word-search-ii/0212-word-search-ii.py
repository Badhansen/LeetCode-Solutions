class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False
    
    def add_word(self, word):
        root = self
        for c in word:
            if c not in root.children:
                root.children[c] = TrieNode()
            root = root.children[c]
        root.end = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for w in words:
            root.add_word(w)
        rows, cols = len(board), len(board[0])
        ans = []
        word = []
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        def dfs(r, c, root):
            if not (0 <= r < rows) or not (0 <= c < cols) or board[r][c] == "#":
                return
            char = board[r][c]
            if char not in root.children:
                return
            board[r][c] = "#"
            root = root.children[char]
            word.append(char)
            if root.end:
                ans.append("".join(word))
                root.end = False
            for x, y in directions:
                dfs(r + x, c + y, root)
            word.pop()
            board[r][c] = char
        
        for r in range(rows):
            for c in range(cols):
                dfs(r, c, root)
        
        return ans