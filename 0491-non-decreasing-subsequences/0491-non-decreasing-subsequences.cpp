class Solution {
public:
    void backtrack(int pos, vector<int>& nums, vector<int> path, set<vector<int>> &answer) {
        if (pos >= nums.size()) {
            if (path.size() >= 2) {
               answer.insert(path);
            }
            return;
        }
        if (path.empty() || path.back() <= nums[pos]) {
            path.push_back(nums[pos]);
            backtrack(pos + 1, nums, path, answer);
            path.pop_back();
        }
        backtrack(pos + 1, nums, path, answer);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> answer;
        vector<int> path;
        backtrack(0, nums, path, answer);
        return vector(answer.begin(), answer.end());
    }
};