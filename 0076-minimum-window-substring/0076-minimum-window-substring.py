class Solution:
    def minWindow(self, s: str, t: str) -> str:
        count = defaultdict(int)
        uniqueCharacter = 0
        for c in t:
            if c not in count:
                uniqueCharacter += 1
            count[c] += 1
        start, end, answer = 0, 0, float("inf")
        index = 0
        while end < len(s):
            count[s[end]] -= 1
            if count[s[end]] == 0:
                uniqueCharacter -= 1
            end += 1
            if uniqueCharacter == 0:
                while uniqueCharacter == 0:
                    if answer > end - start:
                        index = start
                        answer = end - start
                    count[s[start]] += 1
                    if count[s[start]] > 0:
                        uniqueCharacter += 1
                    start += 1
        return "" if answer == float('inf') else s[index:index+answer]
