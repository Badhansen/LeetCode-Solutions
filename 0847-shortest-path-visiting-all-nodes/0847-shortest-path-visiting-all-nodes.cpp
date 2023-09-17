class Solution {
private:
    map<pair<int, int>, int> dp;
    int allMask;
public:
    int solve(int node, int mask, vector<vector<int>>& graph){
        if(dp[{node, mask}] != 0){
            return dp[{node, mask}];
        }
        if((mask & (mask - 1)) == 0){
            return 0;
        }
        dp[{node, mask}] = INT_MAX - 1;
        for(auto &v : graph[node]){
            if ((mask & (1 << v)) != 0){
                int taken = solve(v, mask, graph);
                int notTaken = solve(v, mask ^ (1 << node), graph);
                dp[{node, mask}] = min(dp[{node, mask}] , 1 + min(taken, notTaken));
            }
        }
        return dp[{node, mask}];
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int len = graph.size();
        allMask = (1 << len) - 1;
        int best = INT_MAX;
        for (int node = 0; node < len; node++) {
            best = min(best, solve(node, allMask, graph));
        }
        return best;
    }
};
