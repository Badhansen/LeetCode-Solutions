class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<int> sources;
        for (auto &e : edges) {
            indegree[e[1]]++;
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                sources.push_back(i);
            }
        }
        return sources;
    }
};