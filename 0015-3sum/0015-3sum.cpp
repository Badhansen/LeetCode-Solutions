class Solution {
public:
    void solve(int i, vector<int> &nums, vector<vector<int>> &res){
        unordered_set<int> seen;
        for(int j = i + 1; j < nums.size(); j++){
            int complement = -nums[i] - nums[j];
            if(seen.count(complement)){
                res.push_back({nums[i], nums[j], complement});
                while(j + 1 < nums.size() && nums[j] == nums[j + 1]){
                    j++;
                }
            }
            seen.insert(nums[j]);
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                solve(i, nums, res);
            }
        }
        return res;
    }
};