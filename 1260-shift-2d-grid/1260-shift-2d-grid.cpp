class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        vector<int> res;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                res.push_back(grid[i][j]);
            }
        }
        k = k % (row * col);
        reverse(res.begin(), res.end());
        rotate(res.begin(), res.begin() + k, res.end());
        reverse(res.begin(), res.end());
        for(int i = 0, idx = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                grid[i][j] = res[idx++];
            }
        }
        return grid;
    }
};