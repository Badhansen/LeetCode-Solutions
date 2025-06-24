class Solution:
    def minWindow(self, s: str, t: str) -> str:
        table = Counter(t)
        n, m = len(s), len(t)
        left, right, max_len, count = 0, 0, float('inf'), 0
        index = 0
        while right < n:
            if s[right] in table:
                table[s[right]] -= 1
                if table[s[right]] >= 0:
                    count += 1
            while count == m:
                if right - left + 1 < max_len:
                    max_len = right - left + 1
                    index = left
                if s[left] in table:
                    table[s[left]] += 1
                    if table[s[left]] > 0:
                        count -= 1
                left += 1
            right += 1
        return "" if max_len == float('inf') else s[index:index + max_len]