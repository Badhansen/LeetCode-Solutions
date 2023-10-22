class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k, right = k;
        int minVal = nums[k], res = 0;
        while (left >= 0 && right < n) {
            minVal = min({minVal, nums[left], nums[right]});
            res = max(res, minVal * (right - left + 1));
            int lVal = (left > 0 ? nums[left - 1] : 0);
            int rVal = (right < n - 1 ? nums[right + 1] : 0);
            if (lVal >= rVal) {
                left -= 1;
            } 
            if (rVal >= lVal) {
                right += 1;
            }
        }
        return res;
    }
};