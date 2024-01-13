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
        vector<int> revArr(arr.begin(), arr.end());
        reverse(revArr.begin(), revArr.end());
        vector<int> suffix = minLen(revArr, target);
        int ans = n + 1;
        for (int i = 0; i < n - 1; i++) {
            ans = min(prefix[i] + suffix[n - 1 - i - 1], ans);
        }
        return ans == n + 1 ? -1 : ans;
    }
};