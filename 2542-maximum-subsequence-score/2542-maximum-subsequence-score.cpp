class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({nums1[i], nums2[i]});
        }
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            if (a.second == b.second) {
               return a.first > b.first;
            }
            return a.second > b.second;
        });
        priority_queue<int, vector<int>, greater<int>> top_k;
        long long top_sum = 0, answer = 0;
        for (int i = 0; i < n; i++) {
            top_sum += pairs[i].first;
            top_k.push(pairs[i].first);
            if (top_k.size() >= k) {
                answer = max(answer, top_sum * pairs[i].second);
                top_sum -= top_k.top();
                top_k.pop();
            }
        }
        return answer;
    }
};