class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1, inc = 0, incPrev = 0, dec = 0, decPrev = INT_MAX;
        for (auto n : nums) {
            if (incPrev < n) {
                inc++;
            } else {  
                inc = 1;
            }
            if (decPrev > n) {
                dec++;
            } else {
                dec = 1;
            }
            incPrev = n;
            decPrev = n;
            res = max(res, max(inc, dec));
        }
        return res;
    }
};