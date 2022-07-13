class Solution {
public:
    int BinarySearch(vector<int>& nums, int left, int right, int target){
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
    int FindPivotIndex(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int result = nums[0];
        int index = 0;
        while (left <= right) {
            if (nums[left] < nums[right]) {
                //result = min(result, nums[left]);
                if (nums[left] < result) {
                    result = nums[left];
                    index = left;
                }
                break;
            } 
            int mid = left + (right - left) / 2;
            //result = min(result, nums[mid]);
            if (nums[mid] < result) {
                result = nums[mid];
                index = mid;
            }
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return index;
    }
    int search(vector<int>& nums, int target) {
        int pivot_index = FindPivotIndex(nums);
        int first_index = BinarySearch(nums, 0, pivot_index - 1, target);
        int second_index = BinarySearch(nums, pivot_index, nums.size() - 1, target);
        if (first_index != -1) {
            return first_index;
        } else {
            return second_index;
        }
    }
};