// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), column = obstacleGrid[0].size(); 
        vector<vector<int>> dp(row, vector<int>(column));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(i == 0 && j == 0){
                    if(obstacleGrid[i][j]) 
                        dp[i][j] = 0;
                    else
                        dp[i][j] = 1;
                }
                else if(i == 0 || j == 0){
                    if(obstacleGrid[i][j]) 
                        dp[i][j] = 0;
                    else if(i == 0)
                        dp[i][j] += dp[i][j - 1];
                    else
                        dp[i][j] += dp[i - 1][j];
                }
                else{
                    if(obstacleGrid[i][j]) 
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[row - 1][column - 1];
    }
};

// Time Complexity: O(M * N), Here M = number of rows and N = number of columns
// Space Complexity: O(M * N), we are storing the result in 2d Dp array so the space complexity is O(M * N)