bool compare(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<int> high(n);
        for(int i = 0; i < n; i++){
            high[i] = events[i][1];
        }
        vector<vector<int>> low;
        sort(events.begin(), events.end(), compare);
        sort(high.begin(), high.end());
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                int l = lower_bound(high.begin(), high.end(), events[i - 1][0]) - high.begin();
                dp[i][j] = max(dp[i - 1][j], events[i - 1][2] + dp[l][j - 1]);
            }
        }
        return dp[n][k];
    }
};