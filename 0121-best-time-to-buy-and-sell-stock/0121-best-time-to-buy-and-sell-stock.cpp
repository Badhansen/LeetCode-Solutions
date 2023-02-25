class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_price = 0, min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            best_price = max(best_price, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return best_price;
    }
};