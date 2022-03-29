class Solution {
public:
    int solve(int pos, vector<int>& nums){
        if(nums[pos] == -1){
            return pos;
        }
        int next = nums[pos];
        nums[pos] = -1;
        return solve(next, nums);
    }
    int findDuplicate(vector<int>& nums) {
        return solve(0, nums);
    }
};
