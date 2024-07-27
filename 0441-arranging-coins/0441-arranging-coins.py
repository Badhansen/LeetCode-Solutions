class Solution:
    def arrangeCoins(self, n: int) -> int:
        def possible(row) -> bool:
            total = row * (row + 1) // 2
            return total > n
        
        left, right, res = 1, n + 1, -1
        while left < right:
            mid = left + (right - left) // 2
            if possible(mid):
                right = mid
            else:
                left = mid + 1
        return left - 1