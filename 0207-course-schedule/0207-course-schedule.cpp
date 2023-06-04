class Solution {
private:
    vector<vector<int>> graph;
    set<int> visited, path;
public:
    bool dfs(int src) {
        if (path.count(src)) {
            return true;
        }
        visited.insert(src);
        path.insert(src);
        bool result = false;
        for (auto dest : graph[src]) {
            if (!visited.count(dest)) {
                result |= dfs(dest);
            }
            if (path.count(dest)) {
                return true;
            }
        }
        path.erase(src);
        return result;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        graph.resize(n + 1);
        for (auto &e : pre){
            graph[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i++) {
            if (dfs(i)) {
                return false;
            }
        }
        return true;
    }
};