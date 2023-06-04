class Solution {
public:
    int FindPivotIndex(const vector<int>& nums){
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid + 1 <= right) {
                if (nums[mid] > nums[mid + 1]) {
                    return mid;
                } 
                if (nums[left] > nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return left;
    }
    int search(vector<int>& nums, int target) {
        int index = FindPivotIndex(nums);
        if (index == nums.size()) {
            auto pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            if (pos == nums.size() || pos == 0 && nums[pos] != target) {
                return -1;
            }
            return pos;
        }
        auto pos = lower_bound(nums.begin(), nums.begin() + index + 1, target) - nums.begin();
        if (pos < nums.size() && nums[pos] == target) {
            return pos;
        } 
        pos = lower_bound(nums.begin() + index + 1, nums.end(), target) - nums.begin();
        if (pos > index && pos < nums.size() && nums[pos] == target) {
            return pos;
        }
        return -1;
    }
};