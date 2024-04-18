class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        
        def dfs(pos):
            if pos == len(nums):
                # res.append(nums.copy())
                res.append(nums[:])
                return
            for i in range(pos, len(nums)):
                nums[i], nums[pos] = nums[pos], nums[i]
                dfs(pos + 1)
                nums[i], nums[pos] = nums[pos], nums[i]
                
        dfs(0)
        return res
        
# Time: O(N*N!)
# Space: O(N!)