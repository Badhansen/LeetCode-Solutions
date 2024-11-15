class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        res = []
        def dfs(pos, path):
            if pos == len(num):
                try:
                    result = eval("".join(path))
                except (SyntaxError, NameError) as e:
                    result = None
                except Exception as e:
                    result = None
                if result == target:
                    res.append("".join(path))
                return
            if pos > len(num):
                return
            for i in range(pos, len(num)):
                if i > pos and num[pos] == '0':
                    break
                n = int(num[pos:i + 1])
                if pos == 0:
                    dfs(i + 1, path + [str(n)])
                else:
                    dfs(i + 1, path + ['*', str(n)])
                    dfs(i + 1, path + ['+', str(n)])
                    dfs(i + 1, path + ['-', str(n)])
        dfs(0, [])
        return res