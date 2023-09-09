class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[1001] = {0};
        dp[0] = 1;  // one way to form sum 0, i.e., using no coin
        for(int i = 1; i <= target; i++){
            for(int c : nums){
                if(i - c >= 0){
                    dp[i] += dp[i - c];
                }
            }
        }
        return dp[target];
    }
};