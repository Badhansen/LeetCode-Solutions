class Solution {
public:
    int findIndex(vector<int>& nums, int key){
        int st = 0, ed = nums.size() - 1, ans = 0;
        while(st <= ed){
            int mid = (st + ed) / 2;
            if(nums[mid] < key){
                ans = mid;
                st = mid + 1;
            }
            else{
                ed = mid - 1;
            }
        }
        return ans + 1;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = INT_MIN;
        for(int n : nums){
            int index = findIndex(dp, n);
            ans = max(ans, index);
            if(dp[index] >= n){
                dp[index] = n;
            }
        }
        return ans;
    }
};