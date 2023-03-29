class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<bool>> visited;
public:
    int solve(int pos, int count, vector<int>& satisfaction) {
        if (pos >= satisfaction.size()) {
            return 0;
        }
        if (visited[pos][count]) {
            return dp[pos][count];
        }
        int notTaken = solve(pos + 1, count, satisfaction);
        visited[pos][count] = true;
        int taken = solve(pos + 1, count + 1, satisfaction) + satisfaction[pos] * (count + 1);
        return max(notTaken, taken);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        visited.resize(n + 1, vector<bool>(n + 1, false));
        sort(satisfaction.begin(), satisfaction.end());
        return solve(0, 0, satisfaction);
    }
};