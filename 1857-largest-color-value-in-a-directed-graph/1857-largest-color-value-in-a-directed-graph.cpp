class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        int m = edges.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<int> sources;
        vector<vector<int>> count(n, vector<int>(26, 0));
        int answer = 0, nodeCount = 0;
        
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                sources.push_back(i);
            }
        }
        while (!sources.empty()) {
            int src = sources.back();
            sources.pop_back();
            answer = max(answer, ++count[src][colors[src] - 'a']);
            nodeCount++;
            for (int dest : graph[src]) {
                for (int i = 0; i < 26; i++) {
                    count[dest][i] = max(count[dest][i], count[src][i]);
                }
                indegree[dest]--;
                if (indegree[dest] == 0) {
                    sources.push_back(dest);
                }
            }
        }
        return nodeCount == n ? answer : -1;
    }
};