const int kMax = 105;

class Solution {
private:
    int dp[kMax][kMax];
    int row, col;
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        row = matrix.size(), col = matrix[0].size();
        memset(dp, 0, sizeof dp);
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] + matrix[r][c] - dp[r][c];
            }
        }
        for (int x1 = 0; x1 < row; x1++) {
            for (int y1 = 0; y1 < col; y1++) {
                for (int x2 = x1; x2 < row; x2++) {
                    for (int y2 = y1; y2 < col; y2++) {
                        if (SumRegion(x1, y1, x2, y2) == target) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
    int SumRegion(int row1, int col1, int row2, int col2) { // O(1)
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};