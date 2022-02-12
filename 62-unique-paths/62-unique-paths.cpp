// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Time Complexity: O(M * N), Here M = number of rows and N = number of columns
// Space Complexity: O(M * N), we are storing the result in 2d Dp array so the space complexity is O(M * N)