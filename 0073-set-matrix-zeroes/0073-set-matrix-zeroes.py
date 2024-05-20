class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows, cols = len(matrix), len(matrix[0])
        srow, scol = set(), set()
        for r in range(rows):
            for c in range(cols):
                if not matrix[r][c]:
                    srow.add(r)
                    scol.add(c)
        for r in range(rows):
            for c in range(cols):
                if r in srow or c in scol:
                    matrix[r][c] = 0
        
        
        