class Solution {
private:
    vector<vector<int>> graph;
public:
    int dfs(int u, vector<int>& informTime){
        int time = 0;
        for(auto &v : graph[u]){
            time = max(time, dfs(v, informTime));
        }
        return informTime[u] + time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        graph.resize(n);
        int answer = 0;
        for(int i = 0; i < n; i++){
            if(manager[i] != -1){
                graph[manager[i]].push_back(i);
            }
        }
        return dfs(headID, informTime);
    }
};