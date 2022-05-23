// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(string str: strs) {
            vector<int> count = countZeroOne(str);
            
            for(int i = m ; i >= count[0]; i--) {
                for(int j = n; j >= count[1]; j--) {
                    dp[i][j] = max(1 + dp[i - count[0]][j - count[1]], dp[i][j]);
                }
            }
        }
        
        return dp[m][n];
    }
    
private:
    vector<int> countZeroOne(string str){
        int length = str.size(), zeros = 0;
        
        for(auto s : str)
            if(s == '0') zeros++;
        
        return {zeros, length - zeros};
    }
};
// Time Complexity: O( M * N), where L is the length of the strs, M and N are the number of zeros and 
// ones respectively

// Space Complexity: O(L * M * N), 3D array Memory table dp is used that why the space compleixty is O(L * M * N)
