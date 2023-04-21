const int Mod = 1e9 + 7;

class Solution {
    int dp[105][105][105];
    int minProfit;
public:
    int ways(int pos, int n, int profits, vector<int>& group, vector<int>& profit) {
        if (pos >= group.size() || n < 0) {
            return profits >= minProfit;
        }
        if (dp[pos][n][profits] != -1) {
            return dp[pos][n][profits];
        }
        int taken = 0, notTaken = 0;
        if (group[pos] <= n) {
            taken = ways(pos + 1, n - group[pos], min(minProfit, profits + profit[pos]), group, profit) % Mod;
        }
        notTaken = ways(pos + 1, n, profits, group, profit) % Mod;
        return dp[pos][n][profits] = (taken + notTaken) % Mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof dp);
        this->minProfit = minProfit;
        return ways(0, n, 0, group, profit);
    }
};