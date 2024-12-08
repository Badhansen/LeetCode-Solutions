class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        lines = [0] * 102
        covered = 0
        for s, e in nums:
            lines[s] += 1
            lines[e + 1] -= 1
        for i in range(1, 101):
            lines[i] += lines[i - 1]
            if lines[i]:
                covered += 1
        return covered