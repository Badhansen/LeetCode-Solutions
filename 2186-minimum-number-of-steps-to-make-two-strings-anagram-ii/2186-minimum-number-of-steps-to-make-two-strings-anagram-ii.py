class Solution:
    def minSteps(self, s: str, t: str) -> int:
        scounts = Counter(s)
        tcounts = Counter(t)
        keys = list(scounts.keys() | tcounts.keys())
        res = 0 
        for k in keys:
            res += abs(scounts[k] - tcounts[k])
        return res
            