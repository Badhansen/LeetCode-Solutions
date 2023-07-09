class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        skip = 0
        for b in bits:
            if skip:
                skip -= 1
                continue
            if not b:
                last = True
            else:
                last = False
                skip = 1
        return last
            