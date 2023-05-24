class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({nums[i], i});
        }
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            if (a.first == b.first) {
                return a.second < b.second;
            } 
            return a.first > b.first;
        });
        
        vector<int> answer;
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 0; i < k; i++) {
            que.push(pairs[i].second);
        }
        while (!que.empty()) {
            answer.push_back(nums[que.top()]);
            que.pop();
        }
        return answer;
    }
};