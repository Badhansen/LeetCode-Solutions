class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(seen.count(complement)){
                return {i, seen[complement]};
            }
            seen[nums[i]] = i;
        }
        return {0, 1};
    }
};