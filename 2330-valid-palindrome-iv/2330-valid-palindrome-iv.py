class Solution:
    def makePalindrome(self, s: str) -> bool:
        count = 0
        left, right = 0, len(s) - 1
        while left < right:
            if s[left] != s[right]:
                count += 1
            left += 1
            right -= 1
        return True if count <= 2 else False