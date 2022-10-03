const int kN = 1e5;
const int kColor = 27;
int dp[kN][kColor];
class Solution {
private:
    string colors;
    vector<int> neededTime;
    int n;
public:
    int solve(int pos, int curr) {
        //cout << pos << " " << curr << endl;
        if (pos >= n) {
            return 0;
        }
        int &ret = dp[pos][curr];
        if (ret != -1) {
            return ret;
        }
        int taken = INT_MAX, not_taken = INT_MAX;
        int index = colors[pos] - 'a' + 1;
        if (index != curr) {
            taken = solve(pos + 1, index);
        }
        not_taken = solve(pos + 1, curr) + neededTime[pos];
        return ret = min(taken, not_taken);
    }
    int minCost(string colors, vector<int>& neededTime) {
        memset(dp, -1, sizeof dp);
        this->colors = colors;
        this->neededTime = neededTime;
        this->n = colors.size();
        return solve(0, 0);
    }
};