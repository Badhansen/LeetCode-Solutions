class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                adj[i][graph[i][j]] = 1;
                adj[graph[i][j]][i] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                queue<int> qt;
                qt.push(i);
                vis[i] = 1;
                while(!qt.empty()){
                    int v = qt.front();
                    qt.pop();
                    for(int j = 0; j < n; j++){
                        if(adj[v][j] && vis[j] == 0){
                            if(vis[v] == 1){
                                vis[j] = 2;
                            }
                            else{
                                vis[j] = 1;
                            }
                            qt.push(j);
                        }
                        else if(adj[v][j] && vis[j] == vis[v]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};