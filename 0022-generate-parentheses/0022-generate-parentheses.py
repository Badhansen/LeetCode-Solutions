class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def generate(pos, n, path, open, close):
            if pos == 2 * n:
                if open == close:
                    res.append(path)
                return
            if open < n:
                generate(pos + 1, n, path + '(', open + 1, close)
            if close < open:
                generate(pos + 1, n, path + ')', open, close + 1)
        generate(0, n, "", 0, 0)
        return res
            
        