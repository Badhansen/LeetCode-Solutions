class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, ans = INT_MAX, n = nums.size(), sum = 0;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            while(sum >= target){
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }
        if(ans != INT_MAX) return ans;
        return 0;
    }
};