// @Author: KING-SEN

class Solution {
private:
    vector<bool> visited;
    vector<int> parent;
    vector<vector<int>> graph;
public:
    bool dfs(int v, int par) { // passing vertex and its parent vertex
        visited[v] = true;
        for (int u : graph[v]) {
            if(u == par) continue; // skipping edge to parent vertex
            if (visited[u]) {
                return true;
            }
            parent[u] = v;
            if (dfs(u, parent[u]))
                return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        visited.resize(n, false);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        graph.resize(n);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        if (dfs(0, -1)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};