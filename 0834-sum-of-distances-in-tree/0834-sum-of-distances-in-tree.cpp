class Solution {
private:
    vector<vector<int>> graph;
    vector<int> ans;
    vector<int> count;
    int N;
public:
    void dfs(int src, int parent) {
        for (auto dest : graph[src]) {
            if (dest != parent) {
                dfs(dest, src);
                count[src] += count[dest];
                ans[src] += ans[dest] + count[dest];
            }
        }
    }
    void dfs2(int src, int parent) {
        for (int dest : graph[src]) {
            if (dest != parent) {
                ans[dest] = ans[src] - count[dest] + N - count[dest];
                dfs2(dest, src);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        graph.resize(n);
        ans.resize(n);
        count.resize(n, 1);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};