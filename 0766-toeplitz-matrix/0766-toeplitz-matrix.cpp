class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < col; i++) {
            int val = matrix[0][i];
            int x = 0, y = i;
            while (x < row && y < col) {
                if (val != matrix[x][y]) {
                    return false;
                }
                x++, y++;
            }
        }
        for (int i = 0; i < row; i++) {
            int val = matrix[i][0];
            int x = i, y = 0;
            while (x < row && y < col) {
                if (val != matrix[x][y]) {
                    return false;
                }
                x++, y++;
            }
        }
        return true;
    }
};
/*
[    0 1 2 3
    [1,2,3,4],
    [5,1,2,3],
    [9,5,1,2]
]
*/