class Solution:
    def maxOperations(self, s: str) -> int:
        res, ones = 0, 0
        s = s + "1"
        move = False
        for c in s:
            if c == "1":
                if move:
                    res += ones
                    move = False
                ones += 1
            else:
                move = True
        return res
                
                