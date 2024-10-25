class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for item in tokens:
            if item in ["+", "-", "*", "/"]:
                num2 = stack.pop()
                num1 = stack.pop()
                res = 0
                if item == "+":
                    res = num1 + num2
                elif item == "-":
                    res = num1 - num2
                elif item == "*":
                    res = num1 * num2
                else:
                    res = int(num1 / num2)
                stack.append(res)
            else:
                stack.append(int(item))
        return stack.pop()