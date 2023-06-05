class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int f = 1, l = nums.size(), res = 0;
        if (nums[0] != f) {
            int pos = find(nums.begin(), nums.end(), f) - nums.begin();
            if (pos != nums.size()) {
                res += pos;
                while (pos > 0) {
                    swap(nums[pos - 1], nums[pos]);
                    pos--;
                }
            }
        }
        if (nums[nums.size() - 1] != l) {
            int pos = find(nums.begin(), nums.end(), l) - nums.begin();
            if (pos != nums.size()) {
                while (pos < nums.size() - 1) {
                    swap(nums[pos + 1], nums[pos]);
                    pos++, res++;
                }
            }
        }
        return res;
    }
};