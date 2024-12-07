class Solution:
    def reorganizeString(self, s: str) -> str:
        counts = Counter(s)
        max_count, letter = 0, ""
        for c, count in counts.items():
            if count > max_count:
                max_count = count
                letter = c
        if max_count > (len(s) + 1) // 2:
            return ""
        ans = [''] * len(s)
        index = 0
        while counts[letter] != 0:
            ans[index] = letter
            index += 2
            counts[letter] -= 1
        for char, count in counts.items():
            while count:
                if index >= len(s):
                    index = 1
                ans[index] = char
                index += 2
                count -= 1
        return ''.join(ans)