class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        vector<pair<int, int>> value;
        for(auto item : count){
            value.push_back({item.second, item.first});
        }
        sort(value.begin(), value.end(), [=](auto a, auto b){
            return a.first > b.first;
        });
        vector<int> answer;
        for(int i = 0; i < k; i++){
            answer.push_back(value[i].second);
        }
        return answer;
    }
};