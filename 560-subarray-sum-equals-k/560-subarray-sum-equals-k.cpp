class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0, curr_sum = 0;
        for(int i = 0; i < n; i++){
            curr_sum += nums[i];
            if(curr_sum == k) ans++;
            if(mp.find(curr_sum - k) != mp.end()) ans += mp[curr_sum - k];
            mp[curr_sum]++;
        }
        return ans;
    }
};