class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
		vector<int> ret;
		for (auto &q : queries) {
			vector<pair<string,int>> val;
			for (int i = 0; i < nums.size(); i++) {
				val.push_back({nums[i].substr(nums[0].size() - q[1]), i});
			}
			sort(val.begin(), val.end());
			ret.push_back(val[q[0]-1].second);
		}
		return ret;
    }
};