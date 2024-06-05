class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        dp = {}
        def dfs(pos, mask):
            if pos == len(nums):
                return float("inf")
            if (pos, mask) in dp:
                return dp[(pos, mask)]
            dp[(pos, mask)] = min(
                abs((mask & nums[pos]) - k),
                abs(nums[pos] - k),
                dfs(pos + 1, mask & nums[pos]),
                dfs(pos + 1, nums[pos])
            )
            return dp[(pos, mask)]
        return dfs(0, nums[0])
            