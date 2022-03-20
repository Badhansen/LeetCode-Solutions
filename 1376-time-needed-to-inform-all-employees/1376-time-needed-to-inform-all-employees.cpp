class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // build graph
        vector<vector<int>> graph(n);
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }
        // dfs
        vector<int> time(n, -1);
        dfs(graph, headID, informTime, time);
        // find max time
        int max_time = 0;
        for (int i = 0; i < time.size(); ++i) {
            max_time = max(max_time, time[i]);
        }
        return max_time;
    }
private:
    void dfs(vector<vector<int>>& graph, int node, vector<int>& informTime, vector<int>& time) {
        if (time[node] != -1) {
            return;
        }
        time[node] = informTime[node];
        for (int i = 0; i < graph[node].size(); ++i) {
            dfs(graph, graph[node][i], informTime, time);
            time[node] = max(time[node], time[graph[node][i]] + informTime[node]);
        }
    }
};