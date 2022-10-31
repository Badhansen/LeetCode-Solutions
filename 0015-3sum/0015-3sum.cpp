// 1 last try

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            } 
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int three_sum = nums[i] + nums[left] + nums[right];
                if (three_sum < 0) {
                    left++;
                } else if (three_sum > 0) {
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

// Time: O(N^2)
// Space: O(1) ~ O(N)