// 1 last try

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int siz = nums.size();
        for(int i = 0; i < siz; i++){
            for(int j = i + 1; j < siz; j++){
                int start = j + 1;
                int end = siz - 1;
                long long sum = (long long)target - (long long)nums[i] - (long long)nums[j];
                while(start < end){
                    if(nums[start] + nums[end] == sum){
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                        int third = nums[start];
                        int forth = nums[end];
                        while(start < end && nums[start] == third) start++;
                        while(start < end && nums[end] == forth) end--;
                    }
                    else if(nums[start] + nums[end] > sum) end--;
                    else start++;
                }
                while(j + 1 < siz && nums[j + 1] == nums[j]) j++;
            }
            while(i + 1 < siz && nums[i + 1] == nums[i]) i++;
        }
        return ans;
    }
};

// Time: O(n^3)
// Space: O(1)