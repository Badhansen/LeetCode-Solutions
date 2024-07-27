class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        def enough(num) -> bool:
            total = (
                num // a + num // b + num // c 
                - num // math.lcm(a, b)
                - num // math.lcm(b, c) 
                - num // math.lcm(c, a) 
                + num // math.lcm(a, math.lcm(b, c))
            )
            return total >= n
        
        left, right = 1, 10 ** 10
        while left < right:
            mid = left + (right - left) // 2
            if enough(mid):
                right = mid
            else:
                left = mid + 1
        return left