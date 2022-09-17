class Solution {
private:
    int dp[1001][1001] = {0};
    bool visited[1001][1001] = {false};
public:
    int dfs(vector<int>& nums, vector<int>& mults, int l, int i) {
        if (i >= mults.size()) {
            return 0;
        }
        if (!visited[l][i]) {
            int r = nums.size() - 1 - (i - l);
            dp[l][i] = max(nums[l] * mults[i] + dfs(nums, mults, l + 1, i + 1), 
                nums[r] * mults[i] + dfs(nums, mults, l, i + 1));
            visited[l][i] = true;
        }
        return dp[l][i];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return dfs(nums, multipliers, 0, 0);
    }
};