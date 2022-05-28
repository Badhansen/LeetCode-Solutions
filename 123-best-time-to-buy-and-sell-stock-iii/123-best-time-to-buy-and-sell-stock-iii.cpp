// @Author: KING-SEN
// 1 last try

class Solution {
private:
    int dp[100005][2][3];
public:
    int maxProfit(int pos, int state, int count, vector<int>& prices){
        if(pos >= prices.size() || count == 0) return 0;
        int& ret = dp[pos][state][count];
        if(ret != -1) return ret;
        ret = INT_MIN;
        if(state == 0){
            ret = max(ret, -prices[pos] + maxProfit(pos + 1, !state, count, prices));
        }
        else{
            ret = max(ret, prices[pos] + maxProfit(pos + 1, !state, count - 1, prices));
        }
        ret = max(ret, maxProfit(pos + 1, state, count, prices));
        return ret;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return maxProfit(0, 0, 2, prices);
    }
};

// Time: O(N * 2 * 3) ~ O(N), N = Length of prices
// Space: O(N * 2 * 3) ~ O(N)