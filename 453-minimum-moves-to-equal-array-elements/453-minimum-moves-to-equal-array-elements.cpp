class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = accumulate(nums.begin(), nums.end(), 0LL) - *min_element(nums.begin(), nums.end()) * n;
        return ans;
    }
};