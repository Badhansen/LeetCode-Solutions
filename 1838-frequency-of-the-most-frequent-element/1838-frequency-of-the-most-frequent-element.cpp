class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size(), start = 0, end;
        long long sum = k;
        
        for(end = 0; end < len; end++){
            sum += nums[end];
            if(sum < 1ll * (end - start + 1) * nums[end]){
                sum -= nums[start++];
            }
        }
        
        return end - start;
    }
};