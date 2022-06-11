class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        
        if(x > sum) return -1;
        
        int target = sum - x, left = 0;
        int ans = INT_MIN, currsum = 0;
        
        for(int right = 0; right < n; right++){
            currsum += nums[right];
            while(left < n && currsum - nums[left] >= target){                
                currsum -= nums[left++];
            }
            if(currsum == target) ans = max(ans, right - left + 1);
        }

        if(ans < 0) return -1;
        return n - ans;
    }
};