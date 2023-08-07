class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows, cols = len(matrix), len(matrix[0])
        start, end = 0, (rows * cols) - 1
        while start <= end:
            mid = (start + end) // 2
            x = mid // cols
            y = mid % cols
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] < target:
                start = mid + 1
            else:
                end = mid - 1
        return False
    
    