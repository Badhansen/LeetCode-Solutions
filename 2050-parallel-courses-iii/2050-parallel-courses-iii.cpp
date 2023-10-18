class Solution {
private:
    vector<vector<int>> graph;
    int maxTime[5 * 10004];
public:
    int dfs(int src, vector<int>& time) {
        if (maxTime[src] != -1) {
            return maxTime[src];
        }
        int res = time[src - 1];
        for (int dest : graph[src]) {
            res = max(res, time[src - 1] + dfs(dest, time));
        }
        maxTime[src] = res;
        return res;
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        graph.resize(n + 1);
        memset(maxTime, -1, sizeof maxTime);
        for (auto r : relations) {
            graph[r[0]].push_back(r[1]);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, dfs(i, time));
        }
        return res;
    }
};