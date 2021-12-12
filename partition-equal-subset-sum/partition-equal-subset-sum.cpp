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