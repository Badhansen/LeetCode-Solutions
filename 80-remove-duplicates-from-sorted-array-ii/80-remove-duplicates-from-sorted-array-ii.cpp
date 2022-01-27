class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2, idx = 0;
        for(auto n : nums){
            if(idx < 2 || n > nums[idx - k])
                nums[idx++] = n;
        }
        return idx;
    }
};