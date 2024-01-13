/*

    1. precalculate at each position, i, the min length of array with target sum from left and from right respectively.
        a. fromLeft[i]: from the leftmost to position, i, (i.e. [0 .. i]), the min length of the array with target sum
        b. fromRight[i]: from the rightmost to position, i, (i.e. [i .. n-1]), the min length of the array with target sum
    2. use DP to find the min sum of length at each pisition, i. (i.e. , dp[i] = fromLeft[i] + fromRight[i+1])
        a. consider the minimal sum of two arrays' length at each index, i. (i.e. min sum of length at index i = min length in the range of [0 .. i] + min length in the range of [i+1 .. n-1])
        b. reverse the given array and apply the same subfunction to simply the code.
    3. complexity
        a. Time complexity : O(N)
        b. Space complexity: O(N)

*/
class Solution {
public:
    vector<int> minLen(vector<int> &nums, int target) {
        int n = nums.size();
        unordered_map<int, int> idx;
        vector<int> ans(n, n + 1);
        int presum = 0;
        idx[0] = -1; // we are calculating length index - index + 1 -> 0 - 0 + 1
        for (int i = 0; i < n; i++) {
            presum += nums[i];
            int len = n + 1;
            if (idx.find(presum - target) != idx.end()) {
                len = i - idx[presum - target];
            }
            idx[presum] = i;
            ans[i] = i == 0 ? len : min(ans[i - 1], len);
        }
        return ans;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix = minLen(arr, target);
        reverse(arr.begin(), arr.end());
        vector<int> suffix = minLen(arr, target);
        int ans = n + 1;
        for (int i = 0; i < n - 1; i++) {
            ans = min(prefix[i] + suffix[n - 1 - i - 1], ans);
        }
        return ans == n + 1 ? -1 : ans;
    }
};