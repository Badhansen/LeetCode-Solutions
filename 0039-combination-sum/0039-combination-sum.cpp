class Solution {
public:
    vector<vector<int>> answer;
    
    void solve(int pos, int target, vector<int>& nums, vector<int> path){
        if(target == 0){
            answer.push_back(path);
            return;
        }
        if(target < 0){
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            path.push_back(nums[i]);
            solve(i, target - nums[i], nums, path);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        solve(0, target, candidates, path);
        return answer;
    }
};