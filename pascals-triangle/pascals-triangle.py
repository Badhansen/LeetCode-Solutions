class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal = [[1], [1, 1]]
        if numRows <= 2:
            return pascal[:numRows]
        else:
            for i in range(2, numRows):
                tmp = [1]
                for j in range(1, len(pascal[i - 1])):
                    l = pascal[i - 1][j - 1] + pascal[i - 1][j];
                    tmp.append(l)
                tmp.append(1)
                pascal.append(tmp)
        return pascal
            
        