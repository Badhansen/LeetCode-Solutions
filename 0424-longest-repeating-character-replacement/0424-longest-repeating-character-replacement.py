class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = defaultdict(int)
        left, ans, maxCount = 0, 1, 0
        for right in range(len(s)):
            count[s[right]] += 1
            maxCount = max(maxCount, count[s[right]])
            while (right - left + 1 - maxCount) > k:
                count[s[left]] -= 1
                left += 1
            ans = max(ans, right - left + 1)
        return ans