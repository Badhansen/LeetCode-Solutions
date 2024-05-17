class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        r, c = len(matrix), len(matrix[0])
        x, y, dir = 0, -1, 1
        res = []
        while r * c > 0:
            # for moving horizontally
            for i in range(c):
                y += dir
                res.append(matrix[x][y])
            r -= 1
            # for moving vertically
            for i in range(r):
                x += dir
                res.append(matrix[x][y])
            c -= 1
            dir *= -1
        return res
# Time: O(R * C) // R = number of rows, C = number of columns
# Space: O(1)
        
        
        