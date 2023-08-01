class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = list()
        
        def backtrack(idx, n, k, path):
            if k == 0:
                ans.append(path[:])
                return
            for i in range(idx, n + 1):
                path.append(i)
                backtrack(i + 1, n, k - 1, path)
                path.pop()
        
        backtrack(1, n, k, [])
        return ans
