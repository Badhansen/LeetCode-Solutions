// @Author: KING-SEN
// Programming Language used: C++

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < len; i++){
            if(prices[i] < minPrice)
                minPrice = prices[i];
            else if(prices[i] - minPrice)
                maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

// Time complexity: O(N), where N is the length of the array
// Space complexity: O(1), only using constant space



