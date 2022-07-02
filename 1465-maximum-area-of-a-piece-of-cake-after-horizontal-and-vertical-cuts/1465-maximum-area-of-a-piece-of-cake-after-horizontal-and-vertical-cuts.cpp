
class Solution {
public:
    int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int horizontalMax = max(horizontalCuts[0] - 0, h - horizontalCuts[horizontalCuts.size() - 1]);                         int verticalMax = max(verticalCuts[0] - 0, w - verticalCuts[verticalCuts.size() - 1]);
        for(int i = 1; i < horizontalCuts.size(); i++){
            horizontalMax = max(horizontalMax, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for(int i = 1; i < verticalCuts.size(); i++){
            verticalMax = max(verticalMax, verticalCuts[i] - verticalCuts[i - 1]);
        }
        int ans = (1ll * horizontalMax * verticalMax) % MOD;
        return ans;
    }
};
