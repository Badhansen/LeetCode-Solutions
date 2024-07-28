class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left, right = 0, num
        while left <= right:
            mid = left + (right - left) // 2
            if mid * mid == num:
                return True
            elif mid * mid > num:
                right = mid - 1
            else:
                left = mid + 1
        return False
    
    def judgeSquareSum(self, c: int) -> bool:
        for a in range(int(c**0.5) + 1):
            b = c - a * a
            if self.isPerfectSquare(b):
                return True
        return False