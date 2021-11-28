// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        
        int include = 0;
        int exclude = 0;
        
        for(int i = 0; i < length; i++){
            int in = include, ex = exclude;
            include = ex + nums[i];
            exclude = max(in, ex);
        }
        
        return max(include, exclude);
    }
};


// Time Complexity: O(N), here N = Length of the Given array
// Space Complexity: O(1), because we are using only Constant memory
