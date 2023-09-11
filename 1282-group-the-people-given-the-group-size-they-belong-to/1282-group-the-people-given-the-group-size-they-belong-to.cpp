class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> groups;
        groups.resize(n + 1);
        for (int i = 0; i < n; i++) {
            groups[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (int i = 1; i <= n; i++) {
            if (groups[i].size() > 0) {
                int id = 0;
                while (id < groups[i].size()) {
                    vector<int> res;
                    int siz = i;
                    while (siz--) {
                        res.push_back(groups[i][id++]);
                    }
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};