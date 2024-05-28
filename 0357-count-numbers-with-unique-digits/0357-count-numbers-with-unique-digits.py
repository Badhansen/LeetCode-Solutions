class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        res = 10
        start, curr = 9, 9
        while n > 1 and start:
            curr *= start
            res += curr
            start -= 1
            n -= 1
        return res
        