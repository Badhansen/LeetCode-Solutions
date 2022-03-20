class Solution {
public:
    int n = 12;
    vector<vector<int>> dp;
    int solve(int pos, int arrows, vector<int>& aliceArrows){
        if(pos >= n){
            return 0;
        }
        if(arrows == 0){
            return 0;
        }
        int &ret = dp[pos][arrows];
        if(ret != -1){
            return ret;
        }
        int taken = 0, notTaken = 0;
        if(aliceArrows[pos] < arrows){
            taken = pos + solve(pos + 1, arrows - aliceArrows[pos] - 1, aliceArrows);
        }
        notTaken = solve(pos + 1, arrows, aliceArrows);
        return ret = max(taken, notTaken);
    }
    void path(int pos, int arrows, vector<int>& aliceArrows, vector<int>& result){
        if(pos >= n || arrows == 0){
            return;
        }
        int taken = 0, notTaken = 0;
        if(aliceArrows[pos] < arrows){
            taken = pos + solve(pos + 1, arrows - aliceArrows[pos] - 1, aliceArrows);
        }
        notTaken = solve(pos + 1, arrows, aliceArrows);
        if(taken > notTaken){
            result[pos] = aliceArrows[pos] + 1;
            path(pos + 1, arrows - aliceArrows[pos] - 1, aliceArrows, result);
        }
        else{
            path(pos + 1, arrows, aliceArrows, result);
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        dp.resize(n + 1, vector<int>(numArrows + 1, -1));
        int ans = solve(0, numArrows, aliceArrows);
        vector<int> result(n, 0);
        path(0, numArrows, aliceArrows, result);
        int res = accumulate(result.begin(), result.end(), 0);
        result[0] += numArrows - res;
        return result;
    }
};