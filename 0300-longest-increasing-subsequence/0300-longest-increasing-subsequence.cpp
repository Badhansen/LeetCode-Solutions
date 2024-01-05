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
        dp.clear();
        int n = nums.size();     
        dp.resize(n, -1);
        int ans = 0;
        for (int i = 0; i < n;i++) {
            ans = max(ans, solve(i, nums));
        }
        return ans;
    }
};