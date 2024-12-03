class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort(key=lambda x:(x[0], -x[1]))
        maps = defaultdict(bool)
        prices, beauties, max_val = [], [], 0
        for p, b in items:
            if p not in maps:
                prices.append(p)
                max_val = max(max_val, b)
                beauties.append(max_val)
                maps[p] = True
        res = []
        for q in queries:
            index = bisect_right(prices, q) - 1
            if index < 0:
                res.append(0)
            else:
                res.append(beauties[index])
        return res