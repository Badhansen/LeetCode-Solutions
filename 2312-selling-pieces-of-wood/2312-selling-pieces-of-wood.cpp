const int MAX_H = 202;
const int MAX_W = 202;

typedef long long LL;

class Solution {
private:
    int price[MAX_H][MAX_W];
    LL dp[MAX_H][MAX_W];
public:
    LL solve(int h, int w){
        if(h <= 0 || w <= 0) return 0ll;
        LL &ret = dp[h][w];
        if(ret != -1) return ret;
        ret = price[h][w];
        for(int r = 1; r <= h / 2; r++){
            ret = max(ret, solve(r, w) + solve(h - r, w));
        }
        for(int c = 1; c <= w / 2; c++){
            ret = max(ret, solve(h, c) + solve(h, w - c));
        }
        return ret;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        memset(dp, -1, sizeof dp);
        for(auto &p : prices){
            price[p[0]][p[1]] = p[2];
        }
        LL ans = solve(m, n);
        return ans;
    }
};


/*
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
*/

/*
// Recursive: TLE
const int MAX_H = 202;
const int MAX_W = 202;

typedef long long LL;

class Solution {
private:
    LL dp[MAX_H][MAX_W];
public:
    LL solve(int h, int w, vector<vector<int>>& prices){
        if(h == 0 || w == 0) return 0;
        
        LL &ret = dp[h][w];
        if(ret != -1) return ret;
        
        ret = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(h >= prices[i][0] && w >= prices[i][1]){
                LL curRet = solve(h - prices[i][0], w, prices) + solve(prices[i][0], w - prices[i][1], prices) + prices[i][2];
                ret = max(ret, curRet);
                curRet = solve(h - prices[i][0], prices[i][1], prices) + solve(h, w - prices[i][1], prices) + prices[i][2];
                ret = max(ret, curRet);
            }
        }
        
        return ret;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        memset(dp, -1, sizeof dp);
        LL ans = solve(m, n, prices);
        return ans;
    }
};
*/