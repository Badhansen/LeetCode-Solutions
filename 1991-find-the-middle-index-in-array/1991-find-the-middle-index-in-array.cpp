// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size(), sum = 0, leftSum = 0;
        for(auto x : nums) sum += x;
        
        for(int i = 0; i < n; i++){
            if(leftSum == sum - leftSum - nums[i]) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
