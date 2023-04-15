class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int K) {
        vector<int> dp(K + 1, 0);
        for (auto& pile : piles) {
            for (int k = K; k >= 1; k--) {
                int pile_sum = 0;
                for(int j = 0; j < min(k, (int)pile.size()); j++) {
                    pile_sum += pile[j];
                    dp[k] = max(dp[k], dp[k - j - 1] + pile_sum);
                }
            }
        }
        return dp[K];
    }
};