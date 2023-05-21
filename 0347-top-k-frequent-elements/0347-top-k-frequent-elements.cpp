// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         int length = nums.size();
//         unordered_map<int, int> count;
//         for(int i = 0; i < length; i++){
//             count[nums[i]]++;
//         }
//         vector<vector<int>> buckets(length + 1);
//         for(auto item : count){
//             buckets[item.second].push_back(item.first);
//         }
//         vector<int> answer;
//         for(int i = length; i >= 0; i--){
//             if (answer.size() == k) {
//                 break;
//             }
//             if (!buckets[i].empty()) {
//                 answer.insert(answer.end(), buckets[i].begin(), buckets[i].end());
//             }
//         }
//         return answer;
//     }
// };

// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto &n : nums) {
            count[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        for (auto [key, val] : count) {
            que.push({val, key});
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<int> answer;
        while (!que.empty()) {
            answer.push_back(que.top().second);
            que.pop();
        }
        return answer;
    }
};

// Time: O(n log k)
// Space: O(n + k)