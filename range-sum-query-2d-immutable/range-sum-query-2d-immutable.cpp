class NumMatrix {
    vector<vector<int>> memo;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) 
            return;
        int col = matrix[0].size();
        if(col == 0)
            return;
        memo.resize(row + 1, vector<int>(col + 1));
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                memo[r][c + 1] = memo[r][c] + matrix[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int r = row1; r <= row2; r++){
            sum += memo[r][col2 + 1] - memo[r][col1];
        }
        return sum;
    }
};
// Time Compexity: O(m) time per query, O(mn) time pre-computation. Here m = row length, n = column length.
// Space Compexity: O(mn). The algorithm uses O(mn) space to store the cumulative sum of all rows.