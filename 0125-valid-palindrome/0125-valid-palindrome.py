class Solution:
    def isPalindrome(self, s: str) -> bool:
        line = ''
        for c in s:
            if c.isalpha() or c.isdigit():
                line += c.lower()
        print(line)
        return line == line[::-1]
    
'''
Time complexity: O(N)
Space complexity: O(N)
'''