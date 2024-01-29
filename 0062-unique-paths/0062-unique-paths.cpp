// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int m, int n){
        if(i > m || j > n) return 0;
        if(i == m && j == n) return 1;
        int& ret = dp[i][j];
        if(ret != -1) return ret;
        ret = 0;
        ret = solve(i + 1, j, m, n) + solve(i, j + 1, m, n);
        return ret;
    }
    int uniquePaths(int m, int n) {
        dp.resize(m + 1, vector<int>(n + 1, -1));
        return solve(1, 1, m, n);
    }
};

// Time Complexity: O(M * N), Here M = number of rows and N = number of columns
// Space Complexity: O(M * N), we are storing the result in 2d Dp array so the space complexity is O(M * N)
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<int> cur(n, 1);
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 cur[j] += cur[j - 1];
//             }
//         }
//         return cur[n - 1];
//     }
// };