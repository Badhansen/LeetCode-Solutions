class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = (1 << 32) - 1
        while (mask & b) > 0:
            s = (a ^ b)
            carry = (a & b) << 1
            a, b = s, carry
            # a, b = (a ^ b), (a & b) << 1
        return (a & mask) if b > 0 else a

            