class Solution:
    def minArraySum(self, nums: List[int], k: int, op1: int, op2: int) -> int:
        dp = defaultdict(int)
        def solve(index, op1, op2):
            if index >= len(nums):
                return 0
            if (index, op1, op2) in dp:
                return dp[(index, op1, op2)]
            res = nums[index] + solve(index + 1, op1, op2)
            if op1:
                res = min(res, (nums[index] + 1) // 2 + solve(index + 1, op1 - 1, op2))
            if op2 and nums[index] >= k:
                res = min(res, nums[index] - k + solve(index + 1, op1, op2 - 1))
            if op1 and op2:
                if nums[index] >= k:
                    res = min(res, (nums[index] - k + 1) // 2 + solve(index + 1, op1 - 1, op2 - 1))
                num = (nums[index] + 1) // 2
                if num >= k:
                    res = min(res, num - k + solve(index + 1, op1 - 1, op2 - 1))
                
            dp[(index, op1, op2)] = res
            return dp[(index, op1, op2)]
        return solve(0, op1, op2)
            