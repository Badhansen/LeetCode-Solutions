class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> freq;
        for (auto &n : nums) {
            if (freq[n] == res.size()) {
                res.push_back({});
            }
            res[freq[n]].push_back(n);
            freq[n]++;
        }
        return res;
    }
};