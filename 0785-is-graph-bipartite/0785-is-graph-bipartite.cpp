class Solution {
public:
    bool IsBipartite(int src, vector<int>& color, const vector<vector<int>> &graph) {
        for (int dest : graph[src]) {
            if (color[dest] == -1) {
                color[dest] = 1 - color[src];
                if (!IsBipartite(dest, color, graph)) {
                    return false;
                } 
            } else if (color[dest] == color[src]) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!IsBipartite(i, color, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};