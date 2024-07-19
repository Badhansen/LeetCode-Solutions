class Solution:
    def minWindow(self, s: str, t: str) -> str:
        hash = defaultdict(int)
        for c in t:
            hash[c] += 1
        n, m = len(s), len(t)
        start, end, maxLen, count = 0, 0, float("inf"), 0
        index = 0
        while end < n:
            if s[end] in hash:
                hash[s[end]] -= 1
                if hash[s[end]] >= 0:
                    count += 1
            while count == m:
                if end - start + 1 < maxLen:
                    maxLen = end - start + 1
                    index = start
                if s[start] in hash:
                    hash[s[start]] += 1
                    if hash[s[start]] > 0:
                        count -= 1
                start += 1
            end += 1
        return "" if maxLen == float('inf') else s[index:index+maxLen]
