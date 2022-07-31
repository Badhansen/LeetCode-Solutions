class Solution {
public:
    void dfs(int src, int dist, vector<int>& cache, vector<int>& edges) {
        if (src != -1 && cache[src] == -1) {
            cache[src] = dist;
            dfs(edges[src], dist + 1, cache, edges);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> cache1(n, -1), cache2(n, -1);
        dfs(node1, 0, cache1, edges);
        dfs(node2, 0, cache2, edges);
        int res = INT_MAX, ans;
        for (int i = 0; i < n; i++) {
            if (min(cache1[i], cache2[i]) >= 0 && max(cache1[i], cache2[i]) < res) {
                res = max(cache1[i], cache2[i]);
                ans = i;
            }
        }
        return res == INT_MAX ? -1 : ans;
    }
};