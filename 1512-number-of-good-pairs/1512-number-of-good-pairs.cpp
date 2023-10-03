class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int length = nums.size();
        int answer = 0;
        unordered_map<int, int> count;
        for(int i = 0; i < length; i++){
            count[nums[i]]++;
        }
        for(auto &[key, value] : count){
            answer += (value * (value - 1) / 2);
        }
        return answer;
    }
};