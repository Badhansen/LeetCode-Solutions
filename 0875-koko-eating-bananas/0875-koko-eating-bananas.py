class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def feasible(speed) -> bool:
            return sum(math.ceil(pile / speed) for pile in piles) <= h
        
        low, high, ans = 1, max(piles), -1
        while low <= high:
            mid = (low + high) // 2
            if feasible(mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        return ans