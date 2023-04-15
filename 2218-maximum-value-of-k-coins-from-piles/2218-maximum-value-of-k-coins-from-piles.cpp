class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int pos, int k, vector<vector<int>>& piles) {
        if (k == 0) {
            return 0;
        }
        if (pos >= piles.size()) {
            return INT_MIN;
        }
        int &taken = dp[pos][k];
        if (taken != -1) {
            return taken;
        }
        taken = 0;
        int sum = 0;
        for (int i = 0; i < piles[pos].size() && i < k; i++) {
            sum += piles[pos][i];
            taken = max(taken, sum + solve(pos + 1, k - i - 1, piles));
        }
        int notTaken = solve(pos + 1, k, piles);
        return dp[pos][k] = max(taken, notTaken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        int m = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, (int)piles[i].size());
        }
        dp.resize(n + 1, vector<int>(max(m, k) + 1, -1));
        int answer = solve(0, k, piles);
        return answer;
    }
};