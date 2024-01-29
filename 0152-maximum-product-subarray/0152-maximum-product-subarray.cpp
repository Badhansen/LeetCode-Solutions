// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int curr_max = nums[0];
        int curr_min = nums[0]; 
        int prev_max;
        for(int i = 1; i < nums.size(); i++){
            prev_max = curr_max;
            curr_max = max({nums[i] * curr_max, nums[i] * curr_min, nums[i]});
            curr_min = min({nums[i] * prev_max, nums[i] * curr_min, nums[i]});
            result = max(result, curr_max);
        }
        return result;
    }
};

/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = *max_element(nums.begin(), nums.end());
        int curr_max = 1, curr_min = 1, prev_max;
        for(auto n : nums){
            prev_max = n * curr_max;
            curr_max = max({n * curr_max, n * curr_min, n});
            curr_min = min({prev_max, n * curr_min, n});
            result = max(result, curr_max);
        }
        return result;
    }
};
*/
// Time Complexity: O(N), where N is the length of the array
// Space Complexity: O(1), Here we used only constant space
