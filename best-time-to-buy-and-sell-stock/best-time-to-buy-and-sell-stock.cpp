// @Author: KING-SEN
// Programming Language used: C++

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        vector<int> dp(length, 0);
        
        dp[length - 1] = prices[length - 1];
        
        for(int i = length - 2; i >= 0; i--){
            dp[i] = max(dp[i + 1], prices[i]);
        }
        
        int answer = 0;
        
        for(int i = 0; i < length; i++){
            answer = max(answer, dp[i] - prices[i]);
        }
        
        return answer;
    }
};

// Time complexity: O(N), where N is the length of the array
// Space complexity: O(N), to store the dp result



