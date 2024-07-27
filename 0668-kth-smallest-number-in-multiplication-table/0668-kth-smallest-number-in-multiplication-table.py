class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        # Determine whether there're at least k values less than or equal to num.
        def enough(num) -> bool:
            count = 0
            for i in range(1, m + 1):
                maxN = min(num // i, n)
                if maxN == 0:
                    break
                count += maxN
            return count >= k
        
        left, right = 1, m * n
        while left < right:
            mid = left + (right - left) // 2
            if enough(mid):
                right = mid
            else:
                left = mid + 1
        return left