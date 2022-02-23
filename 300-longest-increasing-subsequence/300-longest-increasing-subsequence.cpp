class Solution {
public:
    int solve(int curr, vector<int>& dp, vector<int>& nums){
        if(curr == 0){
            return 1;
        }
        
        int &ret = dp[curr];
        
        if(ret != -1){
            return ret;
        }
        
        ret = 1;
        
        for(int i = curr - 1; i >= 0; i--){
            if(nums[curr] > nums[i]){
                ret = max(ret, 1 + solve(i, dp, nums));
            }
        }
        
        return ret;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            ans = max(ans, solve(i, dp, nums));
        }

        return ans;
    }
};