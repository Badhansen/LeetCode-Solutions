// @Author: KING-SEN

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int min_val = INT_MAX, max_val = INT_MIN;
        bool sorted = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                sorted = false;
            }
            if (!sorted) {
                min_val = min(min_val, nums[i]);
            }
        }
        sorted = true;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                sorted = false;
            }
            if (!sorted) {
                max_val = max(max_val, nums[i]);
            }
        }
        int left, right;
        for (left = 0; left < n; left++) {
            if (min_val < nums[left]) {
                break;
            }
        }
        for (right = n - 1; right >= 0; right--) {
            if (max_val > nums[right]) {
                break;
            }
        }
        int total = right - left + 1;
        return total < 0 ? 0 : total;
    }
};