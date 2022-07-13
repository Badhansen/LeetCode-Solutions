class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            while(left < right && nums[left] == nums[left + 1]){
                left++;
            }
            while(left < right && nums[right] == nums[right - 1]){
                right--;
            }
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return true;
            }
            // Left sorted portion
            if (nums[left] <= nums[mid]) {
                // [4, 5, 6, 7, 0, 1, 2, 3]
                //           m     t
                /*
                if (target > nums[mid]) {
                    left = mid + 1;
                } else if (target < nums[left]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
                */
                if (target > nums[mid] or target < nums[left]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                // [4, 5, 6, 7, 0, 1, 2, 3]
                //    2(t)        1(t)  m  
                /*
                if (target < nums[mid]) {
                    right = mid - 1;
                } else if (target > nums[right]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
                */
                if (target < nums[mid] or target > nums[right]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};