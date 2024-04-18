class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []
        
        def dfs(i, target, subset):
            if target == 0:
                res.append(subset)
                return
            if target < 0 or i >= len(candidates):
                return
            dfs(i + 1, target - candidates[i], subset + [candidates[i]])
            while i + 1 < len(candidates) and candidates[i] == candidates[i + 1]:
                i += 1
            dfs(i + 1, target, subset)
        
        dfs(0, target, [])
        return res
