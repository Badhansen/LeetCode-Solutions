class Solution {
public:
    int dp[10001];
    int rec(int pos, vector<int>& nums){
        if(pos >= nums.size() - 1) return 0;
        if(pos + nums[pos] >= nums.size() - 1) return 1;
        if(dp[pos] != -1) return dp[pos];
        int ret = INT_MAX / 2;
        for(int i = 1; i <= nums[pos]; i++){
            ret = min(ret, 1 + rec(pos + i, nums));
        }
        return dp[pos] = ret;
    }
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec(0, nums);
    }
};