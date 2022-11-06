const int kMax = 100;
const long long kInf = 1e18;
class Solution {
public:
    long long dp[kMax + 1][kMax + 1][kMax + 1];
    long long solve(int r, int f, int k, vector<int>& robot, vector<vector<int>>& factory) {
        if (r == robot.size()) {
            return 0ll;
        }
        if (f == factory.size()) {
            return kInf;
        }
        if (dp[r][f][k] != -1) {
            return dp[r][f][k];
        }
        long long include = kInf;
        long long exclude = solve(r, f + 1, 0, robot, factory);
        if (k < factory[f][1]) {
            include = abs(robot[r] - factory[f][0]) + solve(r + 1, f, k + 1, robot, factory);
        }
        return dp[r][f][k] = min(include, exclude);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        memset(dp, -1, sizeof dp);
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        long long ans = solve(0, 0, 0, robot, factory);
        return ans;
    }
};