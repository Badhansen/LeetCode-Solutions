class Solution {
private:
    vector<vector<int>> graph;
    vector<int> vis;
    int height;
    int vertex;
public:
    void dfs(int u, int level){
        vis[u] = 1;
        for(auto &v : graph[u]){
            if(vis[v] == 0){
                dfs(v, level + 1);
            }
        }
        if(level > height){
            height = level;
            vertex = u;
        }
        vis[u] = 0;
    }
    void pathFind(int u, int &target, vector<int>& path, vector<int>& ans){
        if(u == target){
            ans = path;
            return;
        }
        vis[u] = 1;
        for(auto &v : graph[u]){
            if(vis[v] == 0){
                path.push_back(v);
                pathFind(v, target, path, ans);
                path.pop_back();
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        vis.resize(n);
        height = 0;
        
        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        dfs(0, 0);
        
        int start = vertex;
        height = 0;
        
        dfs(start, 0);
        
        int end = vertex;
        
        vector<int> path;
        vector<int> ans;
        
        path.push_back(start);
        
        pathFind(start, end, path, ans);
        
        if(ans.size() & 1){
            return {ans[ans.size() / 2]};
        }
        else{
            return {ans[ans.size() / 2], ans[ans.size() / 2 - 1]};
        }
    }
};