class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<vector<int>>& triangle, int r, int c){
        // Base Case
        if(r == triangle.size() - 1 && c < triangle[r].size()){
            return triangle[r][c];
        }
        if(r >= triangle.size() || c >= triangle[r].size()){
            return INT_MAX / 2;
        }
        
        int &ret = dp[r][c];
        
        if(ret != -1) return ret;
        
        ret = min(solve(triangle, r + 1, c), solve(triangle, r + 1, c + 1)) + triangle[r][c];
        
        return ret;
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int maxCol = triangle[row - 1].size();
        
        dp.resize(row, vector<int>(maxCol, -1));
        
        return solve(triangle, 0, 0);
    }
};