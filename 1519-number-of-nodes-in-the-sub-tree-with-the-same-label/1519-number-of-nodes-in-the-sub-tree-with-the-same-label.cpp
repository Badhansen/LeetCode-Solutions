class Solution {
private:
    vector<vector<int>> graph;
    vector<vector<int>> answer;
    vector<bool> visited;
public:
    void dfs(int src) {
        visited[src] = true;
        for (auto dest : graph[src]) {
            if (!visited[dest]) {
                dfs(dest);
                for (int i = 0; i < 26; i++) {
                   answer[src][i] += answer[dest][i];
                }
            }
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        graph.resize(n);
        answer.resize(n);
        visited.resize(n, false);
        for (int i = 0; i < n; i++) {
            answer[i].resize(26, 0);
            answer[i][labels[i] - 'a'] = 1;
        }
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(0);
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = answer[i][labels[i] - 'a'];
        }
        return result;
    }
};