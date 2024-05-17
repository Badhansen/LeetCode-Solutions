class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # matrix.reverse()
        # n = len(matrix)
        # for r in range(n):
        #     for c in range(r + 1, n):
        #         matrix[r][c], matrix[c][r] = matrix[c][r], matrix[r][c]
        n = len(matrix)
        
        for i in range(n // 2):
            for j in range(i, n - i - 1):
                # save the top element
                top = matrix[i][j]
                
                # top <- left
                matrix[i][j] = matrix[n - j - 1][i]
                
                # left <- bottom
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]
                
                # bottom <- right
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
                
                # right <- top
                matrix[j][n - i - 1] = top