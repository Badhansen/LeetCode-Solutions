const int kMax = 505;

class Solution {
private:
    int dp[kMax][kMax];
public:
    int solve(int pos, int walls, vector<int>& cost, vector<int>& time) {
        if (walls >= cost.size()) {
            return 0;
        }
        if (pos >= cost.size()) {
            if (walls >= cost.size()) {
                return 0;
            } else {
                return INT_MAX / 2;
            }
        }
        if (dp[pos][walls] != -1) {
            return dp[pos][walls];
        }
        int taken = solve(pos + 1, walls + time[pos] + 1, cost, time) + cost[pos];
        int notTaken = solve(pos + 1, walls, cost, time);
        return dp[pos][walls] = min(taken, notTaken);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof dp);
        int answer = solve(0, 0, cost, time);
        return answer;
    }
};