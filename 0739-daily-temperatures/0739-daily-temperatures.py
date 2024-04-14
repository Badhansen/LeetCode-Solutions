class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = list()
        result = [0] * len(temperatures)
        for i, n in enumerate(temperatures):
            while stack and temperatures[stack[-1]] < n:
                result[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
        return result
'''
Time: O(N), N = Length of temperatures
Space: O(N)
'''