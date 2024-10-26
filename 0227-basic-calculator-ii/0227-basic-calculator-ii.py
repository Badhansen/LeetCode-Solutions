class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        operation = '+'
        s += operation
        res = 0
        for c in s:
            if c.isdigit():
                res = res * 10 + int(c)
            if c in "+-*/":
                if operation == "+":
                    stack.append(res)
                elif operation == "-":
                    stack.append(-res)
                elif operation == "*":
                    stack.append(stack.pop() * res)
                else:
                    stack.append(int(stack.pop() / res))
                operation = c
                res = 0
        return sum(stack)
                    