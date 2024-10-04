class Solution:
    def removeStars(self, s: str) -> str:
        length = len(s)
        stack = []
        res = []
        for i in range(len(s) - 1, -1, -1):
            if s[i] == '*':
                stack.append('*')
            else:
                if stack:
                    stack.pop()
                else:
                    res.append(s[i])
        return "".join(reversed(res))