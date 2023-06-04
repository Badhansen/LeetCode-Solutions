class Solution {
public:
    void solve(int i, vector<int> &nums, vector<vector<int>> &res){
        unordered_set<int> seen;
        for(int j = i + 1; j < nums.size(); j++){
            int complement = -nums[i] - nums[j];
            if(seen.count(complement)){
                res.push_back({nums[i], nums[j], complement});
                while(j + 1 < nums.size() && nums[j] == nums[j + 1]){
                    j++;
                }
            }
            seen.insert(nums[j]);
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            if(i == 0 || nums[i] != nums[i - 1]){
                solve(i, nums, res);
            }
        }
        return res;
    }
};
/*
// 1 last try

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
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
*/