class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        subset = []
        def dfs(pos, target):
            if target == 0:
                res.append(subset[:])
                return
            if target < 0:
                return
            
            for i in range(pos, len(candidates)):
                subset.append(candidates[i])
                dfs(i, target - candidates[i])
                subset.pop()
            
        dfs(0, target)
        return res
            
                    