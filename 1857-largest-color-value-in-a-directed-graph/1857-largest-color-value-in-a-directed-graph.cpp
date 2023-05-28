// @Author: KING-SEN

class Solution {
private:
    unordered_set<int> visited, path;
    vector<vector<int>> graph;
public:
    int dfs(int src, string& colors, vector<vector<int>>& count) {
        if (path.count(src)) {
            return INT_MAX;
        }
        if (visited.count(src)) {
            return 0;
        }
        visited.insert(src);
        path.insert(src);
        int color_index = colors[src] - 'a';
        count[src][color_index] = 1;
        
        for (auto dest : graph[src]) {
            if (dfs(dest, colors, count) == INT_MAX) {
                return INT_MAX;
            }
            for (int i = 0; i < 26; i++) {
                count[src][i] = max((color_index == i ? 1 : 0) + count[dest][i], count[src][i]);
            }
        }
        path.erase(src);
        return *max_element(count[src].begin(), count[src].end());
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        int m = edges.size();
        graph.resize(n);
        vector<vector<int>> count(n, vector<int>(26, 0));
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer = max(answer, dfs(i, colors, count));
        }
        return answer == INT_MAX ? -1 : answer;
    }
};