// @Author: KING-SEN
// 1 last try

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer = {-1, -1};
        
        if(nums.size() == 0) return answer;
        
        int position = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if(position == nums.size() || nums[position] != target) 
            return answer;

        answer[0] = position;
        
        answer[1] =  upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        answer[1]--;
        return answer;
    }
};

// Time: O(2 log N) ~ O(log N), N = Length of array
// Space: O(1)