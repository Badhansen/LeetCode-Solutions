class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int pos, int d, vector<int>& nums) {
        //cout << pos << " " << d << endl;
        if (pos >= nums.size()) {
            if (d != 0) return 1e9;
            return 0;
        }
        int &ret = dp[pos][d], max_val = -1;
        if (ret != -1) {
            return ret;
        }
        ret = 1e9;
        for (int i = pos; i < nums.size(); i++) {
            max_val = max(max_val, nums[i]);
            if (d) {
                ret = min(ret, max_val + solve(i + 1, d - 1, nums));
            }
        }
        return ret;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        dp.resize(n + 1, vector<int> (d + 1, -1));
        int ans = solve(0, d, jobDifficulty);
        if (ans >= 1e9) {
            return -1;
        }
        return ans;
    }
};