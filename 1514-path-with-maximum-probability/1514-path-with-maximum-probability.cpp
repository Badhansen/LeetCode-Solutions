const double kEsp = 0.00001;

class Solution {
private:
    vector<vector<pair<int, double>>> graph;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        graph.resize(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }        
        priority_queue<pair<double, int>> qt;
        vector<double> dist(n, 0.0);
        qt.push({1.0, start});
        dist[start] = 1.00;
        while (!qt.empty()) {
            int src = qt.top().second;
            double weight = qt.top().first;
            qt.pop();
            if (src == end) {
                return weight;    
            }
            for (int i = 0; i < graph[src].size(); i++) {
                int dest = graph[src][i].first;
                double dweight = graph[src][i].second;
                if (dist[dest] < weight * dweight) {
                    dist[dest] = weight * dweight;
                    qt.push({dist[dest], dest});
                }
            }
        }
        return 0.0;
    }
};