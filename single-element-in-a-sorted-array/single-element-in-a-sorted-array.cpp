//@Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int low = 0, high = len - 1;
        
        if(len == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[len - 1] != nums[len - 2]) return nums[len - 1];
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }
            else if((mid & 1) && nums[mid] == nums[mid - 1] || 
              !(mid & 1) && nums[mid] == nums[mid + 1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};

// Time Complexity: O(log N), here N = length of the array.
// Space Complexity: (1), here we used only constant space.