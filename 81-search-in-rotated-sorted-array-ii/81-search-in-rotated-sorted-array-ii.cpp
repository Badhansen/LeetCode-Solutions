class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0){
            return false;
        }
        int low = 0, high = len - 1;
        while(low <= high){
            while(low < high && nums[low] == nums[low + 1]){
                low++;
            }
            while(low < high && nums[high] == nums[high - 1]){
                high--;
            }
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};