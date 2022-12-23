class Solution {
private:
    vector<set<int>> graph;
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        graph.resize(n + 1);
        vector<int> indegree(n + 1, 0);
        for (auto e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        vector<int> odd_degree;
        int size;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] & 1) {
                odd_degree.push_back(i);
            }
        }
        size = odd_degree.size();
        if (size == 0) {
            return true;
        }
        else if (size == 2) {
            if (!graph[odd_degree[0]].count(odd_degree[1])) {
                return true;
            }
            for (int i = 1; i <= n; i++) {
                if (!graph[odd_degree[0]].count(i) && !graph[odd_degree[1]].count(i)) {
                    return true;
                }
            }
            return false;
        }
        else if (size == 4) {
            if (!graph[odd_degree[0]].count(odd_degree[1]) && !graph[odd_degree[2]].count(odd_degree[3])
               || !graph[odd_degree[0]].count(odd_degree[2]) && !graph[odd_degree[1]].count(odd_degree[3])
               || !graph[odd_degree[0]].count(odd_degree[3]) && !graph[odd_degree[1]].count(odd_degree[2])) {
                return true;
            }
            return false;
        }
        return false;
    }
};