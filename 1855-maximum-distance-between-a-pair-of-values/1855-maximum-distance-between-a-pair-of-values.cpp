// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, ans = 0;
        while(i < n && j < m){
            if(nums1[i] > nums2[j]){
                i++;
            }
            else{
                ans = max(ans, j - i);
                j++;
            }
        }
        return ans;
    }
};

// Time: O(N + M) // N = length of nums1, M = length of nums2
// Space: O(1)