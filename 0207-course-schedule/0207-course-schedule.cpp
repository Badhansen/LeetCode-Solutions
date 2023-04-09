class Solution {
private:
    vector<vector<int>> graph;
    vector<int> visited;
public:
    bool dfs(int u) {
        if (visited[u] == 1) return true; // Already visited
        if (visited[u] == 0) { // Not visited
            visited[u] = 1; // mark as visited
            for(auto &v : graph[u]){
                if(dfs(v)){ // if in any path I can find a visited node then there is an cycle
                    return true;
                }
            }   
        }
        visited[u] = 2; // Mark as done.
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        graph.resize(n + 1);
        visited.resize(n + 1, 0);
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