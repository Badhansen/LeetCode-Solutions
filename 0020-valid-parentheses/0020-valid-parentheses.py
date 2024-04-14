class Solution:
    def isValid(self, s: str) -> bool:
        maps = {')': '(', '}': '{', ']': '['}
        stack = []
        for c in s:
            if not c in maps:
                stack.append(c)
            else:
                if stack and stack[-1] == maps[c]:
                    stack.pop()
                else:
                    return False
        return not stack
'''
Time Complexity: O(N), Where N is the length of the string
Space Complexity: O(N), We have to store up to the N characters in the stack
'''