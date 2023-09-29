class Solution {
public:
    bool isInc(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
    bool isDec(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        if (isInc(nums) || isDec(nums)) {
            return true;
        }
        return false;
    }
};