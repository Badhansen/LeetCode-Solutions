const int kMaxRoutes = 500;
class Solution {
private:
    map<int, vector<int>> _bus_routes;
    vector<int> _graph[kMaxRoutes + 1];
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                _bus_routes[routes[i][j]].push_back(i);
            }
        }
        for (auto [key, value] : _bus_routes) {
            int length = value.size();
            for (int i = 0; i < length - 1; i++) {
                for (int j = i + 1; j < length; j++) {
                    _graph[value[i]].push_back(value[j]);
                    _graph[value[j]].push_back(value[i]);
                }
            }
        }
        map<int, int> target_map;
        queue<array<int, 2>> que;
        vector<bool> visited(kMaxRoutes, false);
        for (auto s : _bus_routes[source]) {
            visited[s] = true;
            que.push({s, 1});
        }
        for (auto t : _bus_routes[target]) {
            target_map[t] = 1;
        }
        while (!que.empty()) {
            int node = que.front()[0], depth = que.front()[1];
            que.pop();
            if (target_map.count(node)) {
                return depth;
            }
            for (auto next_node : _graph[node]) {
                if (!visited[next_node]) {
                    que.push({next_node, depth + 1});
                    visited[next_node] = true;
                }
            }
        }
        return -1;
    }
};