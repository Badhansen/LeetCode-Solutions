// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 1);
//         for(int i = 0; i < n; i++){
//             for (int j = 0; j < i; j++) {
//                 if (nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//         }
        
//         return *max_element(dp.begin(), dp.end());
//     }
// };
class Solution {
private:
    vector<int> dp;
public:
    int solve(int pos, vector<int>& nums) {
        if (pos >= nums.size()) {
            return 1;
        }
        int &ret = dp[pos];
        if (ret != -1) {
            return ret;
        }
        ret = 1;
        for (int i = pos + 1; i < nums.size(); i++) {
            if (nums[pos] < nums[i]) {
                ret = max(ret, 1 + solve(i, nums));
            }
        }
        return ret;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();     
        dp.resize(n, -1);
        int ans = 0;
        for (int i = 0; i < n;i++) {
            ans = max(ans, solve(i, nums));
        }
        return ans;
    }
};