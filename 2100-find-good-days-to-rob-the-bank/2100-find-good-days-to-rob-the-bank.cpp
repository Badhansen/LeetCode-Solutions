// @Author: KING-SEN

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        // Building an non increasing array from left to right and from right to left
        int n = security.size();
        vector<int> presum(n + 1, 0), suffsum(n + 1, 0);
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (security[i - 1] >= security[i]) {
                cnt++;
            } else {
                cnt = 0;
            }
            presum[i] = cnt;
        }
        cnt = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (security[i + 1] >= security[i]) {
                cnt++;
            } else {
                cnt = 0;
            }
            suffsum[i] = cnt;
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (presum[i] >= time && suffsum[i] >= time) {
                result.push_back(i);
            }
        }
        return result;
    }
};

