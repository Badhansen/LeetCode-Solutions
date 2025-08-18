class Solution:
    def dfs(self, pos, candidates, target, subset, res):
        if target == 0:
            res.append(subset[:])
            return
        if target < 0:
            return
        for i in range(pos, len(candidates)):
            subset.append(candidates[i])
            self.dfs(i, candidates, target - candidates[i], subset, res)
            subset.pop()
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        subset = []
        self.dfs(0, candidates, target, subset, res)
        return res

''' 
At each index we have 2 options. Either keep the current element or skip the current element.
Make a recursion tree of this selection. We can select an element multiple times so one call 
with same index another call from next index.
'''

# class Solution:
#     def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
#         res = []
        
#         def dfs(i, target, subset):
#             if target == 0:
#                 res.append(subset)
#                 return
#             if target < 0 or i >= len(candidates):
#                 return
#             dfs(i, target - candidates[i], subset + [candidates[i]])
#             dfs(i + 1, target, subset)
        
#         dfs(0, target, [])
#         return res

'''
Time: O(2^T * K), T = Target value, K = Average length of the combinations
Space: O(K * x), hypothatical space complexity
'''
            
                    