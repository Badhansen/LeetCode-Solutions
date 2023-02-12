const int kLimit = 1e5 + 5;
class Solution {
    vector<vector<int>> graph;
    int seats;
public:
    long long dfs(int src, int parent, int depth, long long& res) {
        long long riders = 1;
        for (auto dest : graph[src]) {
            if (dest != parent) {
                riders += dfs(dest, src, depth + 1, res);
            }
        }
        if (depth == 0) {
            return res;
        }
        res += (riders / seats) * depth + (riders % seats ? 1 : 0);
        return riders % seats;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        this->seats = seats;
        int n = roads.size();
        graph.resize(n + 1);
        for (auto e : roads) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        long long res = 0;
        return dfs(0, -1, 0, res);
    }
};