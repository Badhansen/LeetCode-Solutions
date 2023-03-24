class Solution {
private:
    vector<vector<int>> graph;
    map<int, map<int, int>> maps;
public:
    void dfs(int src, vector<bool>& visited, int &ans) {
        visited[src] = true;
        for (auto e : graph[src]) {
            if (!visited[e]) {
                if (maps[src].count(e)) ans++;
                dfs(e, visited, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        for (auto edge : connections) {
            maps[edge[0]][edge[1]] = 1;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        vector<bool> visited(n, false);
        dfs(0, visited, ans);
        return ans;
    }
};