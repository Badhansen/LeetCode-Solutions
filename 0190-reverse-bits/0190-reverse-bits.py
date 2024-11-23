class Solution:
    def reverseBits(self, n: int) -> int:
        mask = (1 << 32) - 1
        res = 0
        for i in range(32):
            if n & (1 << i):
                res = res | (1 << (31 - i))
                # res &= mask
        return res