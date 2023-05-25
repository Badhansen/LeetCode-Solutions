class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (auto &r : relations) {
            graph[--r[0]].push_back(--r[1]);
            indegree[r[1]]++;
        }
        queue<int> sources;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                sources.push(i);
            }
        }
        int semesters = 0, nodes = 0;
        while (!sources.empty()) {
            int size = sources.size();
            semesters++;
            for (int i = 0; i < size; i++) {
                int src = sources.front();
                nodes++;
                sources.pop();
                for (auto dest : graph[src]) {
                    indegree[dest]--;
                    if (indegree[dest] == 0) {
                        sources.push(dest);
                    }
                }
            }
        }
        return nodes == n ? semesters : -1;
    }
};