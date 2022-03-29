// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int ret = 0;
        for(int i = 0; i < len; i++){
            int id = abs(nums[i]);
            if(nums[id] < 0){
                return id;
            }
            nums[id] *= -1;
        }
        return 0;
    }
};

// Time Complexity: O(N), Here N = length of the array
// Space Complexity: O(1) 