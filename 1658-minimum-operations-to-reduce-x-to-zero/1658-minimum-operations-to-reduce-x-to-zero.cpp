/*
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
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<long long, int> seen;
        long long currsum = 0;
        int ans = INT_MAX;
        
        for(int i = n - 1, j = 1; i >= 0; i--, j++){
            currsum += nums[i];
            seen[currsum] = j;
        }
        
        if(seen[x]) ans = seen[x];
        currsum = 0;
        
        for(int i = 0; i < n; i++){
            currsum += nums[i];
            
            if(currsum == x) ans = min(ans, i + 1);
            if(seen[x - currsum]) ans = min(ans, i + 1 + seen[x - currsum]);
        }
        
        return ans > n ? -1 : ans;
    }
};