// @Author: KING-SEN

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int oddIdx = 1, len = nums.size();
        for(int evenIdx = 0; evenIdx < len; evenIdx += 2){
            if(nums[evenIdx] & 1){
                while(nums[oddIdx] & 1){
                    oddIdx += 2;
                }
                swap(nums[evenIdx], nums[oddIdx]);
            }
        }
        return nums;
    }
};