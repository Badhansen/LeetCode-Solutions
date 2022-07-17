class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> ans;
        for (int i = 0; i < q; i++) {
            int len = queries[i][1];
            int k = queries[i][0];
            vector<pair<string, int>> value;
            for (int j = 0; j < n; j++) {
                int size = nums[j].size();
                string val = nums[j].substr(size - len);
                value.push_back({val, j});
            }
            sort(value.begin(), value.end());
            ans.push_back(value[k - 1].second);
        }
        return ans;
    }
};