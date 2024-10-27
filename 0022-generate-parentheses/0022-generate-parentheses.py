class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def generate(pos, n, path, open, close):
            if pos == 2 * n:
                if open == close:
                    res.append("".join(path))
                return
            if open < n:
                path.append('(')
                generate(pos + 1, n, path, open + 1, close)
                path.pop()
            if close < open:
                path.append(')')
                generate(pos + 1, n, path, open, close + 1)
                path.pop()
        generate(0, n, [], 0, 0)
        return res
            
        