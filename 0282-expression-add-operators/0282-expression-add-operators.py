class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        res = []
        def dfs(start, path, total, last):
            if start == len(num) and total == target:
                res.append("".join(path))
                return
            if start > len(num):
                return
            for i in range(start, len(num)):
                if i > start and num[start] == '0':
                    break
                n = int(num[start: i + 1])
                if total is None:
                    dfs(i + 1, [str(n)], n, n)
                else:
                    dfs(i + 1, path + ['*', str(n)], total - last + last * n, last * n)
                    dfs(i + 1, path + ['+', str(n)], total + n, n)
                    dfs(i + 1, path + ['-', str(n)], total - n, -n)
                    
        dfs(0, [], None, None)
        return res