class Solution {
private:
    map<int, vector<int>> graph;
public:
    void dfs(int src, int parent, vector<int>& res) {
        res.push_back(src);
        for (auto dest : graph[src]) {
            if (dest != parent) {
                dfs(dest, src, res);
            }
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
                break;
            }
        }
        vector<int> res;
        dfs(src, -1, res);
        return res;
    }
};