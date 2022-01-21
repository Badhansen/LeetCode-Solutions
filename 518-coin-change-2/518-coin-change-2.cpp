class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int ways[amount + 1];
        memset(ways, 0, sizeof ways);
        ways[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= amount; j++){
                ways[j] += ways[j - coins[i]];
            }
        }
        return ways[amount];
    }
};