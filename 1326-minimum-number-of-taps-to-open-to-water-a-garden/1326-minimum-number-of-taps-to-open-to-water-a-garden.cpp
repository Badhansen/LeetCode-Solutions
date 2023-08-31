class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1);
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = max(0, i + ranges[i]);
            
            maxReach[left] = max(maxReach[left], right);
        }
        int taps = 0;
        int currEnd = 0, end = 0;
        for (int i = 0; i <= n; i++) {
            if (i > end) {
                return -1;
            }
            if (i > currEnd) {
                taps++;
                currEnd = end;
            }
            end = max(end, maxReach[i]);
        }
        return taps;
    }
};