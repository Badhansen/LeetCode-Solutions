# Explanation : https://www.youtube.com/watch?v=vcv3REtIvEo

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stack = []
        left = [0] * n
        right = [0] * n
        # Filling the left
        for i in range(n):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            left[i] = stack[-1] + 1 if stack else 0
            stack.append(i)
        stack.clear()
        for i in range(n - 1, -1, -1):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            right[i] = stack[-1] - 1 if stack else n - 1
            stack.append(i)
        max_area = 0
        for i in range(n):
            max_area = max(max_area, heights[i] * (right[i] - left[i] + 1))
        return max_area
                     
        