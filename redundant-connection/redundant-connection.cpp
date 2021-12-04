class Solution {
private:
    vector<vector<int>> graph;
    map<int, bool> vis;
public:
    bool dfs(map<int, bool>& vis, vector<vector<int>>& graph, int u, int pr){
        if(vis.find(u) != vis.end()) return true;
        vis[u] = true;
        for(auto v : graph[u]){
            if(v == pr) continue;
            if(dfs(vis, graph, v, u)){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        graph.resize(n + 1);
        for(auto &el : edges){
            graph[el[0]].push_back(el[1]);
            graph[el[1]].push_back(el[0]);
            vis.clear();
            if(dfs(vis, graph, el[0], -1)) return el;
        }
        return {0, 0};
    }
};