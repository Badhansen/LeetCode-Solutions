const int kMod = 1e9 + 7;

class Solution {
private:
    int dp[15][(1 << 14) + 1];
public:
    int solve(int prev, int mask, vector<int>& nums) {
        if (mask == (1 << nums.size()) - 1) {
            return 1;
        }
        int &ret = dp[prev + 1][mask];
        if (ret != -1) {
            return ret;
        }
        ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (prev == -1 || !(mask & (1 << i)) && (nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0)) {
                ret = (ret + solve(i, mask | (1 << i), nums)) % kMod;
            }
        }
        return dp[prev + 1][mask] = ret;
    }
    int specialPerm(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return solve(-1, 0, nums);
    }
};