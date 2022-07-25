// @Author: KING-SEN
// 1 last try

typedef long long LL;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        LL left = 0, currsum = 0, res = 0;
        unordered_map<LL, LL> prevsum;
        
        for(LL right = 0; right < n; right++){
            currsum += nums[right];
            
            if(currsum == k) res = right + 1;
            
            if(!prevsum.count(currsum)) prevsum[currsum] = right;
            
            if(prevsum.count(currsum - k)){
                res = max(res, right - prevsum[currsum - k]);
            }
        }
        
        return res;
    }
};

// Time: O(N), N = Length of the array
// Space: O(N)