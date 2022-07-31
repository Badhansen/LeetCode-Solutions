class Solution {
private:
    vector<vector<int>> graph;
    vector<int> cycle, dist;
    int answer = -1;
public:
    void dfs(int src, int c, int res, vector<int>& edges) {
        if (dist[src] != -1) {
            if (cycle[src] != c) return;
            answer = max(answer, res - dist[src]);
            return;
        }
        dist[src] = res;
        cycle[src] = c;
        if (edges[src] != -1) {
            dfs(edges[src], c, res + 1, edges);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        graph.resize(n);
        cycle.resize(n, 0);
        dist.resize(n, -1);
        int cycle_count = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] == -1) {
                dfs(i, cycle_count, 0, edges);
                cycle_count++;
            }
        }
        return answer;
    }
};