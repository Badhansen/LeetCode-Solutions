class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> answer;
        int n = nums.size(); 
        for (int i = 0; i < (1 << n); i++) {
            vector<int> path;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    path.push_back(nums[j]);
                }
            }
            bool flag = true;
            for (int j = 1; j < path.size(); j++) {
                if (path[j] < path[j - 1]) {
                    flag = false;
                }
            }
            if (flag && path.size() >= 2) {
                answer.insert(path);
            }
        }
        return vector<vector<int>> (answer.begin(), answer.end());
    }
};