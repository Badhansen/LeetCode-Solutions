class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        deque<int> res;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                res.push_back(grid[i][j]);
            }
        }
        k = k % (row * col);
        while(k--){
            int item = res.back();
            res.pop_back();
            res.push_front(item);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                grid[i][j] = res.front();
                res.pop_front();
            }
        }
        return grid;
    }
};