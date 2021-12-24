class Solution {
public:
    void solve(int pos, int n, vector<int>& nums, vector<vector<int>>& ans){
        if(pos == n){
            ans.push_back(nums);
            return;
        }
        for(int i = pos; i < n; i++){
            swap(nums[pos], nums[i]);
            solve(pos + 1, n, nums, ans);
            swap(nums[pos], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        solve(0, len, nums, ans);
        return ans;
    }
};