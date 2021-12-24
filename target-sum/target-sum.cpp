class Solution {
public:
    map<pair<int, int>, int> dp;
    
    int solve(int currentIndex, int sum, int target, vector<int>& nums){
        if(currentIndex == nums.size()){
            if(sum == target)
                return 1;
            else
                return 0;
        }
        
        if(dp.find({currentIndex, sum}) != dp.end())
            return dp[{currentIndex, sum}];
        
        int result1 = solve(currentIndex + 1, sum + nums[currentIndex], target, nums);
        int result2 = solve(currentIndex + 1, sum - nums[currentIndex], target, nums);
        
        return dp[{currentIndex, sum}] = result1 + result2;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, target, nums);    
    }
};