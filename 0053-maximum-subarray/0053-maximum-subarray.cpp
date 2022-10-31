class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            curr = max(curr + nums[i], nums[i]);
            result = max(result, curr);
        }
        
        return result;
    }
};
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0], curr_sum = 0;
        for(int i = 0; i < n; i++){
            if(curr_sum < 0) curr_sum = 0;
            curr_sum += nums[i];
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};
*/
// Time: O(N)
// Spce: O(1)