// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, product = 1, res = 0;
        for(int right = 0; right < n; right++){
            product *= nums[right];
            
            while(left < right && product >= k){
                product /= nums[left++];
            }
            
            if(product < k) res += right - left + 1;
        }
        
        return res;
    }
};

// Time: O(N), N = length of the nums
// Space: O(1)