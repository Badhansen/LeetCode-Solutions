// @Author: KING-SEN
// 1 last try

class Solution {
private:
    int dp[1005][2][105];
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
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return maxProfit(0, 0, k, prices);
    }
};


// Time: O(N * 2 * K) ~ O(N * K), N = Length of prices, K = number of transactions
// Space: O(N * 2 * K) ~ O(N * K)