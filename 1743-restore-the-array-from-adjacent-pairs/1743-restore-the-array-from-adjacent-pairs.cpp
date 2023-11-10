class Solution {
private:
    map<int, vector<int>> graph;
    map<int, bool> visited;
    
public:
    void dfs(int src, vector<int>& res) {
        if (visited[src]) {
            return;
        }
        visited[src] = true;
        res.push_back(src);
        for (auto dest : graph[src]) {
            dfs(dest, res);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for (auto adj : adjacentPairs) {
            int u = adj[0], v = adj[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int src;
        for (auto item : graph) {
            if (item.second.size() == 1) {
                src = item.first;
            }
        }
        vector<int> res;
        dfs(src, res);
        return res;
    }
};