// Programming Language Used: C++
class Solution {
public:
    int pivot(vector<int>& nums, int low, int high) {
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] <= nums[high]) {
                high = mid;
            }
        }
        return low;
    }
    int findMin(vector<int>& nums) {
        int result = nums[pivot(nums, 0, nums.size() - 1)];
        return result;
    }
};

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int left = 0, right = nums.size() - 1, result = nums[0];
//         while (left <= right) {
//             if (nums[left] < nums[right]) {
//                 result = min(result, nums[left]);
//                 break;
//             } 
//             int mid = left + (right - left) / 2;
//             result = min(result, nums[mid]);
//             if (nums[mid] >= nums[left]) {
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }
//         return result;
//     }
// };


// Time complexity: O(log N), where N = number of elements in the num array
// Space Complexity: O(1)