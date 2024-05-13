class Solution:
    def findMaximumElegance(self, items: List[List[int]], k: int) -> int:
        items.sort(key=lambda item:(-item[0], item[1]))
        seen = set()
        res = total = 0
        curr = []
        for i, (p, c) in enumerate(items):
            if i < k:
                if c in seen:
                    curr.append(p)
                total += p
            elif c not in seen:
                if not curr:
                    break
                total += p - curr.pop()
            seen.add(c)
            res = max(res, total + len(seen) ** 2)
        return res