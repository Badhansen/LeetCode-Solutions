/*
//@Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp){
        if(amount < 0) return INT_MAX / 2;
        if(amount == 0) return 0;
        
        int& ret = dp[amount];
        
        if(ret != -1) return ret;
        ret = INT_MAX / 2;
        
        for(auto coin : coins){
            ret = min(ret, 1 + solve(coins, amount - coin, dp));
        }
        
        return ret;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int answer = solve(coins, amount, dp);
        
        if(answer >= INT_MAX / 2) return -1;
        return answer;
    }
};

// Time Complexity: O(Amount * N), N = denomination count.In the worst case the recursive tree of the algorithm has of height S and the algorithm solves only Amount subproblems because  it caches precalculated solutions in a table. Each subproblem is computed with N iterations. Therefore there is O(Amount * n) time complexity
// Space Complexity:  O(Amount), where we use extra space for the memoization table for amount.
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        for(int i = 0; i<=amount; i++) dp[i] = 1e9;
        dp[0] = 0;
        for(int i = 1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(coins[j] <= i) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};