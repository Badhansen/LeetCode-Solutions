# KING-SEN

class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        stack = []
        # Decresing stack for maximum element in the range
        for right in range(n + 1):
            while stack and (right == n or nums[stack[-1]] <= nums[right]):
                j = stack.pop()
                left = -1 if not stack else stack[-1]
                res += (j - left) * (right - j) * nums[j]
            stack.append(right)
        stack = []
        # Increasing stack for minimum element in the range
        for right in range(n + 1):
            while stack and (right == n or nums[stack[-1]] >= nums[right]):
                j = stack.pop()
                left = -1 if not stack else stack[-1]
                res -= (j - left) * (right - j) * nums[j]
            stack.append(right)
        return res