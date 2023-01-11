class Solution {
private:
    vector<vector<int>> graph;
public:
    int dfs(int src, int parent, vector<bool>& hasApple) {
        int totalTime = 0, childTime = 0;
        for (auto dest : graph[src]) {
            if (dest == parent) continue;
            childTime = dfs(dest, src, hasApple);
            if (childTime || hasApple[dest]) totalTime += childTime + 2;
        }
        return totalTime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph.resize(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, hasApple);
    }
};