class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int numViolations = 0, n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if (nums[i] <= nums[i + 1]) {
                continue;
            }
            if (numViolations) {
                return false;
            }
            // We want to decrease the left pointer
            // [3, 4, 2, 3]
            if (i == 0 || nums[i + 1] >= nums[i - 1]) {
                nums[i] = nums[i + 1];
            } else {
                nums[i + 1] = nums[i];
            }
            numViolations++;
        }
        return true;
    }
};

// Time: O(N)
// Space: O(1)