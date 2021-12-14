// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int rob(vector<int>& nums, int start, int end){
        int include = 0;
        int exclude = 0;
        
        for(int i = start; i <= end; i++){
            int in = include, ex = exclude;
            include = ex + nums[i];
            exclude = max(in, ex);
        }
        
        return max(include, exclude);
    }
    
    int rob(vector<int>& nums) {
        int length = nums.size();
    
        if(length == 1) return nums[0];
        
        int maxOne = rob(nums, 1, length - 1);
        int maxTwo = rob(nums, 0, length - 2);
        
        return max(maxOne, maxTwo);
    }
};

// Time Complexity: O(N), here N = Length of the Given array
// Space Complexity: O(1), we are using only constant space
