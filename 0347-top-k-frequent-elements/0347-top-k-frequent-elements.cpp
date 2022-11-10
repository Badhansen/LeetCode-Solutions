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