// @Author: KING-SEN
// Programming Language Used: C++
// Recursive Approach

class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()){
            return INT_MAX / 2;
        }

        if(r == grid.size() - 1 && c == grid[0].size() - 1){
            return grid[r][c];
        }
        
        int &ret = dp[r][c];
        
        if(ret != -1) return ret;
        
        ret = min(solve(grid, r + 1, c), solve(grid, r, c + 1)) + grid[r][c];
        
        return ret;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(), vector<int> (grid[0].size(), -1));
        
        return solve(grid, 0, 0);
    }
};

// Time Complexity: O(row * column), here row = grid row size and collumn = grid column size
// Space Complexity: O(row * column)

// Iterative Approach

/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=1; i<n; i++) grid[0][i] += grid[0][i - 1];
        for(int i=1; i<m; i++) grid[i][0] += grid[i - 1][0];
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
*/