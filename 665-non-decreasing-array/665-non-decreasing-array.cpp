class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0; //the number of changes
        for(int i = 1; i < nums.size() && cnt <= 1; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                //modify nums[i-1] of a priority
                if(i-2<0 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1]; //have to modify nums[i]
            }
        }
        return cnt <= 1;
    }
};