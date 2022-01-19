class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int pos, int state, vector<int>& prices){
        if(pos >= prices.size()) return 0;
        int &ret = dp[pos][state];
        if(ret != -1) return ret;
        int buy = 0, sell = 0, cool = 0;
        if(state == 0){
            buy = solve(pos + 1, 1, prices) - prices[pos];
        }
        else{
            sell = solve(pos + 2, 0, prices) + prices[pos];
        }
        cool = solve(pos + 1, state, prices);
        return ret = max({buy, sell, cool});
    }
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        dp.resize(len + 1, vector<int>(2, -1));
        return solve(0, 0, prices);
    }
};