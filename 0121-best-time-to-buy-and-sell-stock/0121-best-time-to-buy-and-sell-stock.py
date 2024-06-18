class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res, minimum = 0, float("inf")
        for price in prices:
            minimum = min(minimum, price)
            res = max(res, price - minimum)
        return res