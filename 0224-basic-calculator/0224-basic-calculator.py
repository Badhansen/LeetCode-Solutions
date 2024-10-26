class Solution:
    def calculate(self, s: str) -> int:
        result, sign = 0, 1
        stack = []
        i = 0
        while i < len(s):
            if s[i] == " ": # For empty space
                i += 1
                continue
            elif s[i].isdigit(): # For digit
                res = 0
                while i < len(s) and s[i].isdigit():
                    res = res * 10 + int(s[i])
                    i += 1
                i -= 1
                result += res * sign
            elif s[i] == "+":
                sign = 1
            elif s[i] == '-':
                sign = -1
            elif s[i] == '(':
                stack.append(result)
                stack.append(sign)
                result, sign = 0, 1
            else:
                result = stack.pop() * result
                result += stack.pop()
            i += 1
        return result
            
                