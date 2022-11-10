class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int res = 1, ans = 1;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i] - 1) {
                res++;
            } else {
                res = 1;
            }
            ans = max(res, ans);
        }
        return ans;
    }
};