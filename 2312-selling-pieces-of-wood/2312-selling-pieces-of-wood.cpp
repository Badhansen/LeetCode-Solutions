const int MAX_H = 202;
const int MAX_W = 202;

typedef long long LL;

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        LL dp[MAX_H][MAX_W] = {0};
        
        for(auto &price : prices){
            dp[price[0]][price[1]] = price[2];
        }
        
        for(int h = 1; h <= m; h++){
            for(int w = 1; w <= n; w++){
                for(int a = 1; a <= h; a++){
                    dp[h][w] = max(dp[h][w], dp[a][w] + dp[h - a][w]);
                }
                for(int a = 1; a <= w; a++){
                    dp[h][w] = max(dp[h][w], dp[h][a] + dp[h][w - a]);
                }
            }
        }
        
        return dp[m][n];
    }
};