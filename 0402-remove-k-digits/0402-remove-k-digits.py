class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for digit in num:
            while stack and k and stack[-1] > digit:
                stack.pop()
                k -= 1
            if digit == '0':
                if stack:
                    stack.append(digit)
            else:
                stack.append(digit)
        while k and stack:
            k -= 1
            stack.pop()
        return "".join(stack) if stack else "0"
        