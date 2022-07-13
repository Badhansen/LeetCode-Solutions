class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
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
        return -1;
    }
};
/*
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
*/