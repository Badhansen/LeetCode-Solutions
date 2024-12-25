class Solution:
    def minSteps(self, s: str, t: str) -> int:
        scounts = Counter(s)
        tcounts = Counter(t)
        res = 0
        for k, v in scounts.items():
            if k in tcounts:
                if tcounts[k] < v:
                    res += v - tcounts[k]
            else:
                res += v
        return res
            