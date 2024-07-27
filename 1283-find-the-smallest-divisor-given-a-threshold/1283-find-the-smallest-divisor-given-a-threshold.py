class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def condition(divisor) -> bool:
            total = sum(math.ceil(num / divisor) for num in nums)
            return total <= threshold
            
        left, right = 1, max(nums)
        while left < right:
            mid = left + (right - left) // 2
            if condition(mid):
                right = mid
            else:
                left = mid + 1
        return left