class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        left = 0
        for right in range(len(pushed)):
            stack.append(pushed[right])
            while stack and stack[-1] == popped[left]:
                stack.pop()
                left += 1
        while stack and left < len(popped) and popped[left] == stack[-1]:
            left += 1
            stack.pop()
        return not stack and left == len(popped)