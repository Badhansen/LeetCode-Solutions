/*
class Solution {
private:
    vector<int> dp;
public:
    int solve(int pos, int sum, vector<int>& nums){
        if(sum == 0)
            return 1;
        if(pos >= nums.size())
            return 0;
        if(dp[sum] != -1)
            return dp[sum];
        dp[sum] = 0;
        for(int i = pos; i < nums.size(); i++){
            if(sum >= nums[i]){
                dp[sum] = solve(i + 1, sum - nums[i], nums);
                if(dp[sum]) 
                    return 1;
            }
        }
        return dp[sum];
    }
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(auto &num : nums){
            target += num;
        }
        dp.resize(target + 1, -1);
        if(target & 1) 
            return false;
        target /= 2;
        return solve(0, target, nums);
    }
};
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int length = nums.size();
        int sum = 0;
        
        for(auto num : nums)
            sum += num;
        
        if(sum & 1) return false;
        
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        
        dp[0] = true;
        
        for(int i = 0; i < length; i++){
            for(int s = sum; s >= nums[i]; s--){
                dp[s] = dp[s] | dp[s - nums[i]];
            }
        }
        
        return dp[sum];
    }
};


