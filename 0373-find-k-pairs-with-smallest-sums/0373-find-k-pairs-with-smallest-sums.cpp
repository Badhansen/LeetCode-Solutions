class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size(), len2 = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> qt;
        vector<vector<int>> answer;
        for (int i = 0; i < len1; i++) {
            qt.push({nums1[i] + nums2[0], {i, 0}});
        }
        while (k && !qt.empty()) {
            auto top = qt.top();
            qt.pop();
            answer.push_back({nums1[top.second.first], nums2[top.second.second]});
            if (top.second.second + 1 < len2) {
                int sum = nums1[top.second.first] + nums2[top.second.second + 1];
                qt.push({sum, {top.second.first, top.second.second + 1}});
            }
            k--;
        }
        return answer;
    }
};