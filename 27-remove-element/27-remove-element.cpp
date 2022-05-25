// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ptr = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == val) continue;
            else{
                nums[ptr++] = nums[i];
            }
        }
        return ptr;
    }
};

// Time: O(N), N = number of elemnents
// Space: O(1)

