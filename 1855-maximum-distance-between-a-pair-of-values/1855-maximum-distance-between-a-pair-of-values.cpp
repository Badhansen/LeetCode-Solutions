class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> minval(n, INT_MAX), maxval(m, INT_MIN);
        for(int i = 0; i < n; i++){
            minval[i] = min(minval[i], nums1[i]);
        }
        for(int i = 0; i < m; i++){
            maxval[i] = max(maxval[i], nums2[i]);
        }
        int cnt1 = 0, cnt2 = 0;
        int ans = 0;
        while(cnt1 < n && cnt2 < m){
            if(minval[cnt1] <= maxval[cnt2]){
                ans = max(ans, cnt2 - cnt1);
                cnt2++;
            }
            else if(minval[cnt1] > maxval[cnt2]){
                cnt1++, cnt2++;
            }
        }
        return ans;
    }
};

// Time: O(N + M) // N = length of nums1, M = length of nums2
// Space: O(N + M)