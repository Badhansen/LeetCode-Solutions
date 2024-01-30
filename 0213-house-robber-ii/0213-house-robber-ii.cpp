// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int solve(int pos, int n, vector<int>& nums, vector<int>& dp){
        if(pos > n){
            return 0;
        }
        if(dp[pos] != -1) return dp[pos];
        int left = solve(pos + 1, n, nums, dp);
        int right = nums[pos] + solve(pos + 2, n, nums, dp);
        return dp[pos] = max(left, right);
    }
    
    int rob(vector<int>& nums) {
        int length = nums.size();
    
        if(length == 1) return nums[0];
        vector<int> dp(length, -1);
        int maxOne = solve(1, length - 1, nums, dp);
        fill(dp.begin(), dp.end(), -1);
        int maxTwo = solve(0, length - 2, nums, dp);
        
        return max(maxOne, maxTwo);
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums, int start, int end){
//         int include = 0;
//         int exclude = 0;
        
//         for(int i = start; i <= end; i++){
//             int in = include, ex = exclude;
//             include = ex + nums[i];
//             exclude = max(in, ex);
//         }
        
//         return max(include, exclude);
//     }
    
//     int rob(vector<int>& nums) {
//         int length = nums.size();
    
//         if(length == 1) return nums[0];
        
//         int maxOne = rob(nums, 1, length - 1);
//         int maxTwo = rob(nums, 0, length - 2);
        
//         return max(maxOne, maxTwo);
//     }
// };

// Time Complexity: O(N), here N = Length of the Given array
// Space Complexity: O(1), we are using only constant space
