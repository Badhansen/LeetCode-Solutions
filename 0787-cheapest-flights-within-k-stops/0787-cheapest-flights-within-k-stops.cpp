class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {   
        vector<int> dp(n, 1e9);
        dp[src] = 0;
        for(int i = 0; i <= K; i++){
            vector<int> t(dp);
            for(auto const &x : flights){
                int u, v, w;
                u = x[0], v = x[1], w = x[2];
                t[v] = min(t[v], dp[u] + w);
            }
            dp = t;
        }
        if(dp[dst] == 1e9)
            return -1;
        return dp[dst];
    }
};