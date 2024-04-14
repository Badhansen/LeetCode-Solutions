class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        answer = 0
        while l < r:
            answer = max(answer, min(height[l], height[r]) * (r - l))
            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1
        return answer
'''
Time complexity: O(n)
Space complexity: O(1)
'''