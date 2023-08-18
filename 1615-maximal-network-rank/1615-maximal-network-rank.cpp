class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> graph(n);
        for (auto r : roads) {
            graph[r[0]].insert(r[1]);
            graph[r[1]].insert(r[0]);
        }
        int res = 0;
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                int rank = graph[a].size() + graph[b].size();
                if (graph[a].count(b)) {
                    rank--;
                }
                res = max(res, rank);
            }
            
        }
        return res;
    }
};