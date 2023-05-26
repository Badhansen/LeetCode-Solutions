// @Author: KING-SEN

class Solution {
public:
    int Solve(int pos, int m, int alice, const vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if (pos >= piles.size()) {
            return 0;
        }
        int &result = dp[pos][m][alice];
        if (result != -1) {
            return result;
        }
        int sum = 0;
        result = alice == 1 ? 0 : 1e9;
        for (int x = 1; x <= 2 * m; x++) {
            if (pos + x > piles.size()) {
                break;
            }
            sum += piles[pos + x - 1];
            if (alice) {
                result = max(result, sum + Solve(pos + x, max(m, x), !alice, piles, dp));
            } else {
                result = min(result, Solve(pos + x, max(m, x), !alice, piles, dp));
            }
        }
        return result;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return Solve(0, 1, 1, piles, dp);
    }
};

// Time: O(n^3)
// Space: O(n^3)