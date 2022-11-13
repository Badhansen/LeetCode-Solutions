const int kMax = 1e5 + 5;
class Solution {
private:
    vector<int> graph[kMax];
    int bob;
    vector<int> dist, amount;
    int answer = INT_MIN;
public:
    void dfs(int src, int parent) {
        if (src == bob) {
            dist[src] = 0;
        }
        for (auto dest : graph[src]) {
            if (dest == parent) {
                continue;
            }
            dfs(dest, src);
            if (dist[dest] != INT_MAX) {
                dist[src] = dist[dest] + 1;
            }
        }
    }
    void dfs2(int src, int parent, int time, int cost) {
        if (time < dist[src]) {
            cost += amount[src];
        } else if (time == dist[src]) {
            cost += amount[src] / 2;
        }
        int child = 0;
        for (auto dest : graph[src]) {
            if (dest != parent) {
                child++;
                dfs2(dest, src, time + 1, cost);
            }
        }
        if (child == 0) {
            answer = max(answer, cost);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        dist.resize(kMax, INT_MAX);
        this->bob = bob;
        this->amount = amount;
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        // for (int i = 0; i < 5; i++) {
        //     cout << dist[i] << " ";
        // }
        dfs2(0, -1, 0, 0);
        return answer;
    }
};