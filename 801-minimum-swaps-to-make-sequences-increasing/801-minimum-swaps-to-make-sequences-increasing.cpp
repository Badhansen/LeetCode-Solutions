// @Author: KING-SEN

class Solution {
private:
    vector<vector<int>> cache_;
public:
    int solve(int index, int swapped, vector<int>& nums1, vector<int>& nums2) {
        // Base case
        if (index == nums1.size()) {
            return 0;
        }
        if (cache_[index][swapped] != -1) {
            return cache_[index][swapped];
        }
        int answer = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        // Previous index swapped or not
        if (swapped) {
            swap(prev1, prev2);
        }
        // No swap
        if (prev1 < nums1[index] && prev2 < nums2[index]) {
            answer = solve(index + 1, 0, nums1, nums2);
        } 
        // Swap
        if (prev2 < nums1[index] && prev1 < nums2[index]) {
            answer = min(answer, 1 + solve(index + 1, 1, nums1, nums2));
        }
        return cache_[index][swapped] = answer;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int len = nums1.size();
        cache_.resize(len + 1, vector<int>(2, -1));
        return solve(1, 0, nums1, nums2);
    }
};