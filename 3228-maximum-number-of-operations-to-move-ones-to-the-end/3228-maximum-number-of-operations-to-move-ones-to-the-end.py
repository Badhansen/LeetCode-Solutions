class Solution:
    def maxOperations(self, s: str) -> int:
        stack = []
        res = 0
        for c in s:
            if c == '1':
                flag = False
                while stack and stack[-1] == '0':
                    flag = True
                    stack.pop()
                if flag:
                    res += len(stack)
            stack.append(c)
        if stack and stack[-1] == '0':
            while stack and stack[-1] == '0':
                stack.pop()
            res += len(stack)
        return res
                
                