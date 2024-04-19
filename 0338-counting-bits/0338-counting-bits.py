class Solution:
    def countBits(self, n: int) -> List[int]:
        # return [i.bit_count() for i in range(0, n + 1)]
        return [bin(i).count('1') for i in range(0, n + 1)]