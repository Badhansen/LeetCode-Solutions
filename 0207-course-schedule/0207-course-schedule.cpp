class Solution {
private:
    vector<vector<int>> graph;
    vector<int> visited;
public:
    bool dfs(int u){
        if(visited[u] == 1)
            return true;
        if(visited[u] == 0){
            visited[u] = 1;
            for(auto &v : graph[u]){
                if(dfs(v)){
                    return true;
                }
            }   
        }
        visited[u] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        graph.resize(n + 1);
        visited.resize(n + 1, 0);
        for(auto &e : pre){
            graph[e[1]].push_back(e[0]);
        }
        for(int i = 0; i < n; i++){
            if(dfs(i)){
                return false;
            }
        }
        return true;
    }
};