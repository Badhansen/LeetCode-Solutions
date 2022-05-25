// @Author: KING-SEN
// 1 last try

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> ans;
        int x = 0, y = -1, dir = 1;
        while(row * col > 0){
            // for moving horizontally
            for(int i = 0; i < col; i++){
                y += dir;
                ans.push_back(matrix[x][y]);
            }
            row--;
            // for moving vertically
            for(int i = 0; i < row; i++){
                x += dir;
                ans.push_back(matrix[x][y]);
            }
            col--;
            dir *= -1;
        }
        return ans;
    }
};

// Time: O(R * C) // R = number of rows, C = number of columns
// Space: O(1)