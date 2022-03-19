// @Author: KINg-SEN

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while(start < end){
            if((nums[start] & 1) && (nums[end] & 1)){
                end--;
            }
            else if(!(nums[start] & 1)){
                start++;
            }
            else{
                swap(nums[start], nums[end]);
                start++, end--;
            }
        }
        return nums;
    }
};