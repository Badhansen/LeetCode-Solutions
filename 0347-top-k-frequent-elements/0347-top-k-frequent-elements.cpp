class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int length = nums.size();
        unordered_map<int, int> count;
        for(int i = 0; i < length; i++){
            count[nums[i]]++;
        }
        vector<vector<int>> buckets(length + 1);
        for(auto item : count){
            buckets[item.second].push_back(item.first);
        }
        vector<int> answer;
        for(int i = length; i >= 0; i--){
            if (answer.size() == k) {
                break;
            }
            if (!buckets[i].empty()) {
                answer.insert(answer.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        return answer;
    }
};

// Time: O(n)
// Space: O(n)
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> m;
//         for (int i = 0; i < nums.size(); i++) {
//             m[nums[i]]++;
//         }
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         for (auto it = m.begin(); it != m.end(); it++) {
//             pq.push({it->second, it->first});
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
//         vector<int> result;
//         while (!pq.empty()) {
//             result.push_back(pq.top().second);
//             pq.pop();
//         }
//         return result;
//     }
// };

// // Time: O(n log k)
// // Space: O(n + k)