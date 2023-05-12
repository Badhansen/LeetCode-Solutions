class Solution {
private:
    vector<long long> dp;
public:
    long long solve(int pos, vector<vector<int>>& questions){
        if(pos >= questions.size()) return 0;
        if(dp[pos] != -1) return dp[pos];
        long long in = questions[pos][0] + solve(pos + questions[pos][1] + 1, questions);
        long long ex = solve(pos + 1, questions);
        return dp[pos] = max(in, ex);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int len = questions.size();
        dp.resize(len + 1, -1);
        return solve(0, questions);
    }
};