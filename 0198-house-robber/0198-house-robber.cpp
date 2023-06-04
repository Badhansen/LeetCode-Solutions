class Solution {
public:
    int solve(int pos, vector<int>& nums, vector<int>& dp){
        if(pos >= nums.size()){
            return 0;
        }
        if(dp[pos] != -1) return dp[pos];
        int left = solve(pos + 1, nums, dp);
        int right = nums[pos] + solve(pos + 2, nums, dp);
        return dp[pos] = max(left, right);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solve(0, nums, dp);
    }
};
/*
// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        
        int include = 0;
        int exclude = 0;
        
        for(int i = 0; i < length; i++){
            int in = include, ex = exclude;
            include = ex + nums[i];
            exclude = max(in, ex);
        }
        
        return max(include, exclude);
    }
};


// Time Complexity: O(N), here N = Length of the Given array
// Space Complexity: O(1), because we are using only Constant memory
*/