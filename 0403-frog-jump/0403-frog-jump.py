class Solution:
    def canCross(self, stones: List[int]) -> bool:
        mark = {}
        dp = {}
        for i in range(len(stones)):
            mark[stones[i]] = i
        
        def go(index, prevjump):
            if index == len(stones) - 1:
                return True
            if (index, prevjump) in dp:
                return dp[(index, prevjump)]
            res = False
            for nxtjump in range(prevjump - 1, prevjump + 2):
                if nxtjump > 0 and (stones[index] + nxtjump) in mark:
                    res = res or go(mark[stones[index] + nxtjump], nxtjump)
            dp[(index, prevjump)] = res
            return res
        
        return go(0, 0)